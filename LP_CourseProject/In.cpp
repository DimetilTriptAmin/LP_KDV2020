#include <fstream>
#include <iostream>
#include "Error.h"
#include "In.h"
#include "Log.h"

namespace In
{
	void addWord(IN* table, Word entry) {
		table->WordArray[int(table->WordAmount)] = entry;
	}

	Word CreateWord(int size, IN table, int curLine, int curCol) {
		if (table.text[table.size - size] == ' ' || table.text[table.size - size] == '|' || table.text[table.size - size] == '\n') return { 0,0,0 };
		Word* Entry = new Word;
		Entry->line = curLine;
		Entry->position = curCol;
		Entry->word = new char[size];
		for (int i = 0; i < size; i++) {
			Entry->word[i] = table.text[table.size - size + i];
		}
		Entry->word[size] = '\0';
		return *Entry;
	}

	IN getin(wchar_t infile[])
	{
		std::ifstream fin(infile);
		if (!fin.is_open()) throw ERROR_THROW(102);

		
		IN ri = {};
		unsigned char symb;
		unsigned char nextSymb;
		bool quotFlag = false;
		int WordSize = 0;
		Word word;

		char s='a';
		int fileSize = 0;
		while (!fin.eof()) {
			fileSize++;
			s = fin.get();
		};
		fileSize--;

		fin.close();
		fin.open(infile);

		int curCol = 0,
			curLine = 0;

		if (fileSize)
		{
			curLine = 1;
			curCol = 1;
		}

		(fileSize > IN_MAX_LEN_TEXT) ? fileSize = IN_MAX_LEN_TEXT : fileSize;

			ri.text = new unsigned char[IN_MAX_LEN_TEXT];
			if (fileSize == IN_MAX_LEN_TEXT)std::cout << "\nВнимание, обьём исходного кода больше допустимого. Возможна потеря данных.\n";
		ri.size = 0;
		ri.ignor = 0;

		while (ri.size < fileSize)
		{
			symb = fin.get();
			if (symb == '"') quotFlag = !quotFlag;
			if (((symb == '\t') || (symb == ' ') || (symb == '\n')) && quotFlag == false && !fin.eof())
			{
				nextSymb = fin.get();
				while ((nextSymb == '\t') || (nextSymb == ' ')) {
					nextSymb = fin.get();
					fileSize--;
					curCol++;
				}
				while (nextSymb == '\n') {
					nextSymb = fin.get();
					fileSize--;
					curLine++;
				}
				if (nextSymb=='=')
				{
					fin.seekg(-1, fin.cur);
					fileSize--;
					continue;
				}
				fin.seekg(-1, fin.cur);
			}

			switch (ri.code[(int)symb])
			{
			case ri.T:
				ri.text[ri.size] = symb;
				ri.size++;
				WordSize++;
				break;
			case ri.F:
				throw ERROR_THROW_IN(103, curLine, curCol);
				break;
			case ri.I:
				ri.ignor++;
				break;
			case ri.D:
				ri.text[ri.size] = symb;
				if (quotFlag != true) {
					nextSymb = fin.get();
					if (nextSymb=='=') {
						if (WordSize != 0) {
						word = CreateWord(WordSize, ri, curLine, curCol);
						addWord(&ri, word);
						ri.WordAmount++;
						WordSize = 0;
						}
						ri.size++;
						ri.text[ri.size] = nextSymb;
						ri.size++;
						WordSize+=2;
						if (WordSize != 0) {
							word = CreateWord(WordSize, ri, curLine, curCol);
							if (word.word != NULL) {
								addWord(&ri, word);
								ri.WordAmount++;
							}
						}
						WordSize = 0;
					}
					else {
						fin.seekg(-1, fin.cur);
						if (WordSize != 0) {
							word = CreateWord(WordSize, ri, curLine, curCol);
							if (word.word != NULL) {
								addWord(&ri, word);
								ri.WordAmount++;
							}
						}
						ri.size++;
						word = CreateWord(1, ri, curLine, curCol);
						if (word.word != NULL) {
							addWord(&ri, word);
							ri.WordAmount++;
						}
						WordSize = 0;
					}
				}
				else {
					WordSize++;
					ri.size++;
				}
				break;
			default:
				ri.text[ri.size] = (char)ri.code[(int)symb];
				if (quotFlag != true) {
					word = CreateWord(WordSize, ri, curLine, curCol);
					if (word.word != NULL) {
						addWord(&ri, word);
						ri.WordAmount++;
					}
					WordSize = 0;
				}
				ri.size++;
				break;
			}

			if (symb == IN_CODE_ENDL)
			{
				curCol = 1;
				curLine++;
			}
			else curCol++;

		}
		if (WordSize) {
			word = CreateWord(WordSize, ri, curLine, curCol);
			addWord(&ri, word);
			ri.WordAmount++;
		}
		ri.text[ri.size] = '\0';
		fin.close();
		ri.lines = curLine;
		ri.WordArray[ri.WordAmount] = { '\0',0,0 };
		return ri;
	}
}
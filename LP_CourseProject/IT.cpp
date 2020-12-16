#include "IT.h"
#include "Math.h"
#include "In.h"
#include "Error.h"
#include <iostream>

namespace IT
{
	void AddLib(		//ƒобавить строку в таблицу идентификаторов
		IdTable& idtable //экземл€р таблицы идентификаторов
	) {
		Entry* func1 = new Entry;
		strcpy(func1->id,"параҐнаць");
		strncpy(func1->prefix, "comm", ID_MAXSIZE);
		func1->iddatatype = LT::BOOL;
		func1->idtype = F;
		func1->parmCount = 2;
	
		Entry* f1parm1 = new Entry;
		strcpy(f1parm1->id, "а");
		f1parm1->iddatatype = LT::STR;
		f1parm1->idtype = P;

		Entry* f1parm2 = new Entry;
		strcpy(f1parm2->id, "б");
		f1parm2->iddatatype = LT::STR;
		f1parm2->idtype = P;

		Entry* func2 = new Entry;
		strcpy(func2->id, "ступень");
		strncpy(func2->prefix, "comm", ID_MAXSIZE);
		func2->iddatatype = LT::INT;
		func2->idtype = F;
		func2->parmCount = 2;

		Entry* f2parm1 = new Entry;
		strcpy(f2parm1->id, "а");
		f2parm1->iddatatype = LT::INT;
		f2parm1->idtype = P;

		Entry* f2parm2 = new Entry;
		strcpy(f2parm2->id, "б");
		f2parm2->iddatatype = LT::INT;
		f2parm2->idtype = P;

		Add(idtable, *func1);
		Add(idtable, *f1parm1);
		Add(idtable, *f1parm2);
		Add(idtable, *func2);
		Add(idtable, *f2parm1);
		Add(idtable, *f2parm2);
	}
	int BinToDec(In::Word word) {
		int result=0;
		int len = strlen(word.word);
		bool isNeg = false;
		if (word.word[0] == '-') isNeg = true;
		for (int i = len-1; i >= 2 + isNeg;i--) {
			if (word.word[i] != '0' && word.word[i] != '1') throw ERROR_THROW_IN(10, word.line, word.position);
			if (word.word[i] == '1') result += pow(2, len - (i+1));
		}
		if (isNeg) result *= -1;
		if (result > 32767) result = 32767;
		if (result < -32768) result = -32767;
		return result;
	}

	int OctToDec(In::Word word) {
		int result=0;
		int len = strlen(word.word);
		bool isNeg = false;
		if (word.word[0] == '-') isNeg = true;

		for (int i = len - 1; i >= 2+isNeg; i--) {
			if (word.word[i] < '0' || word.word[i] > '7') throw ERROR_THROW_IN(10, word.line, word.position);
			result += (word.word[i]-48)*pow(8, len - (i + 1));
		}
		if (isNeg) result *= -1;
		if (result > 32767) result = 32767;
		if (result < -32768) result = -32767;
		return result;
	}

	IdTable Create(int size) {
		IdTable CreatedTable = { size, 0, new Entry[size] };
		return CreatedTable;
	}

	void Add(		//ƒобавить строку в таблицу идентификаторов
		IdTable& idtable, //экземл€р таблицы идентификаторов
		Entry entry	//строка таблицы идентификаторов
	) {
		idtable.table[idtable.size] = entry;
		idtable.size++;
		if (idtable.size > TI_MAXSIZE) throw ERROR_THROW(6);
	}

	Entry GetEntry(		// получить строку таблицы идентификаторов
		IdTable& idtable, // экземл€р таблицы ид
		int n			// строка таблицы ид
	) {
		Entry entry;
		entry.idxfirstLE = (idtable.table[n]).idxfirstLE;
		for (int i = 0; i < ID_MAXSIZE; i++)
			entry.id[i] = (idtable.table[n]).id[i];
		entry.iddatatype = (idtable.table[n]).iddatatype;
		entry.idtype = (idtable.table[n]).idtype;
		entry.value = (idtable.table[n]).value;
		strcpy_s(entry.prefix, (idtable.table[n]).prefix);
		return entry;
	}

	int IsId(   // возврат: номер строки если есть, TI_NULLIDX(если нет)
		IdTable& idtable, // экземл€р таблицы ид
		Entry entry // идентификатор
	) {
		char* idPointer;
		char* prefixPointer;
		for (int i = 0; i < idtable.size; i++) {
			idPointer = idtable.table[i].id;
			prefixPointer = idtable.table[i].prefix;
			if ((!strcmp(entry.id, idPointer) && !strcmp(entry.prefix, prefixPointer)) || (!strcmp(entry.id, idPointer) && !strcmp(idtable.table[i].prefix, "comm"))) return i;
		}
		return TI_NULLIDX;
	}

	int IsLit(   // возврат: номер строки если есть, TI_NULLIDX(если нет)
		IdTable& idtable, // экземл€р таблицы ид
		Entry entry // идентификатор
	) {
		switch (entry.iddatatype) {
		case 1: {
			for (int i = 0; i < idtable.size; i++) {
				if (idtable.table[i].idtype == entry.idtype && idtable.table[i].value.vstr.len == entry.value.vstr.len) {
					for (int j = 0; j < entry.value.vstr.len; j++) {
						if (entry.value.vstr.str[j] != idtable.table[i].value.vstr.str[j]) return TI_NULLIDX;
					}
					return i;
				}
			}
		}
		case 2: {
			for (int i = 0; i < idtable.size; i++) {
				if (idtable.table[i].idtype == entry.idtype && idtable.table[i].value.vint == entry.value.vint) return i;
			}
		}
		}
		return TI_NULLIDX;
	}

	void IdFill(IdTable& idtable, LT::LexTable& lexemTable, In::IN code) {
		char** visSpace = new char* [3];
		for (int i = 0; i < 3; i++) {
			visSpace[i] = new char[ID_MAXSIZE];
		}
		char main[] = { "comm" };
		visSpace[0] = main;

		int funcindex = 0;
		unsigned short index = 0;
		bool isMainFunc = false;
		bool isParm = false;
		bool isBool = false;
		bool isFunc = false;
		bool isInt = false;
		bool isStr = false;
		bool isDec = false;
		int isId;

		for (int i = 0; i < lexemTable.size; i++) {
			if (!strcmp(code.WordArray[i].word, "цэлы"))isInt = !isInt;
			if (!strcmp(code.WordArray[i].word, "лаг≥чны"))isBool = !isBool;
			
			if (!strcmp(code.WordArray[i].word, "радок"))isStr = !isStr;
			
			if (lexemTable.table[i].lexema[0] == 'd')isDec = true;
			if (lexemTable.table[i].lexema[0] == 'f') {
				isFunc = !isFunc;
			}


			if (lexemTable.table[i].lexema[0] == '(' && isFunc) {
				isParm = !isParm;
				isFunc = !isFunc;
			}
			if (lexemTable.table[i].lexema[0] == ')' && isParm) isParm = !isParm;

			if (lexemTable.table[i].lexema[0] == 'i')
			{
				IT::Entry* newId = new IT::Entry;
				if (isFunc) {
					strncpy(newId->prefix, "comm", ID_MAXSIZE);
					visSpace[index] = code.WordArray[i].word;
					funcindex = idtable.size;
				}
				else strncpy(newId->prefix, visSpace[index], ID_MAXSIZE);
				strncpy((newId->id), code.WordArray[i].word, ID_MAXSIZE);

				if (strlen(code.WordArray[i].word)> ID_MAXSIZE)newId->id[ID_MAXSIZE] = '\0';
				else newId->id[strlen(code.WordArray[i].word)] = '\0';

				if (strlen(visSpace[index]) > ID_MAXSIZE)newId->prefix[ID_MAXSIZE] = '\0';
				else newId->prefix[strlen(visSpace[index])] = '\0';

				isId = IsId(idtable, *newId);
				if (isFunc && isId != TI_NULLIDX) throw ERROR_THROW_IN(17, code.WordArray[i].line, code.WordArray[i].position);
				if (isId != TI_NULLIDX) {
					if (isDec) { throw ERROR_THROW_IN(11, code.WordArray[i].line, code.WordArray[i].position); isDec = false; }
					lexemTable.table[i].idxTI = isId;
					isInt = false;
					isStr = false;
					isBool = false;
					delete newId;
					continue;
				}
				else {
					newId->idxfirstLE = i;
					if (isParm) {
						newId->idtype = P;
						idtable.table[funcindex].parmCount++;
					}
					else if (isFunc) {
						newId->idtype = F;
						if (!strcmp(code.WordArray[i].word, "галоҐна€")) isMainFunc = true;
					}
					else if (isDec) {
						newId->idtype = V;
						isDec = false;
					}
					if (isBool) {
						newId->value.vbool = false;
						newId->iddatatype = LT::BOOL;
						isBool = !isBool;
					}
					else if (isInt) {
						newId->value.vint=0;
						newId->iddatatype = LT::INT;
						isInt = !isInt;
					}
					else if (isStr) {
						newId->value.vstr.len = 0;
						strcpy_s(newId->value.vstr.str,"");
						newId->iddatatype = LT::STR;
						isStr = !isStr;
					}
					else throw ERROR_THROW_IN(4, code.WordArray[i].line, code.WordArray[i].position);
					lexemTable.table[i].idxTI = idtable.size;
					Add(idtable, *newId);
				}
			}

			if (lexemTable.table[i].lexema[0] == 'l') {
				IT::Entry* newId = new IT::Entry;
				strncpy_s((newId->id), ID_MAXSIZE * 2, "л≥тэрал", 3);
				newId->idxfirstLE = i;
				newId->idtype = IT::L;
				newId->iddatatype = lexemTable.table[i].type;
				switch (newId->iddatatype)
				{
				case 3: {
					if (!strcmp(code.WordArray[i].word, "так"))  newId->value.vbool = true;
					else  newId->value.vbool = false;
					break;
				}
				case 2: {
					if (code.WordArray[i].word[0]=='2') newId->value.vint = BinToDec(code.WordArray[i]); 
					else newId->value.vint = OctToDec(code.WordArray[i]);
						break;
				}
				case 1: {
					newId->value.vstr.len = strlen(code.WordArray[i].word);
					for (int j = 0; j < newId->value.vstr.len; j++) newId->value.vstr.str[j] = code.WordArray[i].word[j];
					newId->value.vstr.str[newId->value.vstr.len] = '\0';
					break;
				}
				default:
					break;
				}
				if (IsLit(idtable, *newId) != TI_NULLIDX) {
					lexemTable.table[i].idxTI = IsLit(idtable, *newId);
					delete newId;
					continue;
				}
				else {
					lexemTable.table[i].idxTI = idtable.size;
					Add(idtable, *newId);
				}
			}
		}

		/*for (int i = 0; i < 3; i++) {
			delete[] visSpace[i];
		}*/
		if (isMainFunc == false) throw ERROR_THROW(16);
		delete[] visSpace;
	}

	void Delete(IdTable& idtable) {
		delete[] idtable.table;
	}

}

#include "FST.h"
#include "Error.h"
#include "IT.h"

namespace LT
{

	LexTable Create(int size) {
		LexTable CreatedTable = { size, 0, new Entry[size] };
		return CreatedTable;
	}

	void Add(		//ƒобавить строку в таблицу идентификаторов
		LexTable& lextable, //экземл€р таблицы идентификаторов
		Entry entry	//строка таблицы идентификаторов
	) {

		lextable.table[lextable.size] = entry;
		lextable.size++;
		if (lextable.size > LT_MAXSIZE) throw ERROR_THROW(5);

	}

	Entry GetEntry(		// получить строку таблицы идентификаторов
		LexTable& lextable, // экземл€р таблицы ид
		int n			// строка таблицы ид
	) {
		Entry entry;
		entry.sn = (lextable.table[n]).sn;
		entry.lexema[0] = (lextable.table[n]).lexema[0];
		entry.idxTI = (lextable.table[n]).idxTI;
		return entry;
	}

	void LexFill(LexTable& lexemTable, In::IN ri) {

		int result = -1;
		int index = 0;
		bool rc = false;
		char lexems[] = { LEX_IF,LEX_ELSE,LEX_INCLUDE,LEX_BOOL,LEX_INTEGER , LEX_STRING, LEX_FUNCTION, LEX_PRINT, LEX_DECLARE, LEX_RETURN, LEX_WHILE, LEX_LEFTBRACE, \
			LEX_BRACELET, LEX_LEFTHESIS, LEX_RIGHTHESIS, LEX_ASSIGN, LEX_SEMICOLON, LEX_COMMA, LEX_LITERAL, LEX_LITERAL,LEX_ID, \
			LEX_DIRSLASH,LEX_BIGGER, LEX_BIGGEREQUAL, LEX_SMALLER, LEX_SMALLEREQUAL, LEX_EQUAL,LEX_NOTEQUAL,\
			LEX_LITERAL, LEX_LITERAL };

		FST::FST fstIf(nullptr, 5, IFNODES);
		FST::FST fstElse(nullptr, 6, ELSENODES);
		FST::FST fstIncl(nullptr, 10, INCLUDENODES);
		FST::FST fstTrue(nullptr, 4, TRUENODES);
		FST::FST fstFalse(nullptr, 3, FALSENODES);
		FST::FST fstInt(nullptr, 5, INTEGERNODES);
		FST::FST fstBool(nullptr, 8, BOOLNODES);
		FST::FST fstStr(nullptr, 6, STRINGNODES);
		FST::FST fstFunc(nullptr, 8, FUNCTIONNODES);
		FST::FST fstPrint(nullptr, 8, PRINTNODES);
		FST::FST fstDec(nullptr, 9, DECLARENODES);
		FST::FST fstRet(nullptr, 8, RETURNNODES);
		FST::FST fstWhile(nullptr, 7, WHILENODES);
		FST::FST fstLeftBracelet(nullptr, 2, LEFTBRACENODES);
		FST::FST fstBracelet(nullptr, 2, BRACELETNODES);
		FST::FST fstLefTheSis(nullptr, 2, LEFTHESISNODES);
		FST::FST fstRightTheSis(nullptr, 2, RIGHTHESISNODES);
		FST::FST fstEql(nullptr, 2, ASSIGNNODES);
		FST::FST fstSemicolon(nullptr, 2, SEMICOLONNODES);
		FST::FST fstComma(nullptr, 2, COMMANODES);
		FST::FST fstId(nullptr, 3, IDNODES);
		FST::FST fstOper(nullptr, 2, OPERATORNODES);
		FST::FST fstBig(nullptr, 2, OPERATORBIGGER);
		FST::FST fstBigEq(nullptr, 3, OPERATORBIGGEREQUAL);
		FST::FST fstSmal(nullptr, 2, OPERATORSMALLER);
		FST::FST fstSmalEq(nullptr, 3, OPERATORSMALLEREQUAL);
		FST::FST fstEq(nullptr, 3, OPERATOREQUAL);
		FST::FST fstNotEq(nullptr, 3, OPERATORNOTEQUAL);
		FST::FST fstStrLit(nullptr, 3, STRLITNODES);
		FST::FST fstIntLit(nullptr, 5, INTLITNODES);
		FST::FST FSTARRAY[] = { fstIf,fstElse,fstIncl, fstBool, fstInt, fstStr,fstFunc,fstPrint,fstDec,fstRet,fstWhile,fstLeftBracelet,fstBracelet,\
				fstLefTheSis,fstRightTheSis,fstEql, fstSemicolon, fstComma, fstFalse, fstTrue, fstId, fstOper,fstBig, fstBigEq, fstSmal, fstSmalEq, fstEq, fstNotEq, fstStrLit, fstIntLit };
		int FSTARRAYSIZE = sizeof(FSTARRAY) / sizeof(FSTARRAY[0]);

		while (ri.WordArray[index].word) {

			result = -1;
			for (int i = 0; i < FSTARRAYSIZE; i++) {
				FSTARRAY[i].string = ri.WordArray[index].word;
				FSTARRAY[i].rstates[0] = 0;
				FSTARRAY[i].position = -1;
				rc = FST::execute(FSTARRAY[i]);
				if (rc)
				{
					result = i;
					LT::Entry* newLexem = new LT::Entry;
					*newLexem->lexema = lexems[i];
					newLexem->sn = ri.WordArray[index].line;
					newLexem->cm = ri.WordArray[index].position;
					newLexem->idxTI = LT_TI_NULLIDX;
					if (result == 18 || result == 19)
						newLexem->type = BOOL;
					if (result == 29)
						newLexem->type = INT;
					if (result == 28)
						newLexem->type = STR;
					
					if (result >= 21 || result <= 27) {
						strncpy_s(newLexem->oper, ri.WordArray[index].word, 2);
						newLexem->oper[2] = 0;
					}
					
					LT::Add(lexemTable, *newLexem);
					break;
				}
			}
			if (result == -1) throw ERROR_THROW_IN(2, ri.WordArray[index].line, ri.WordArray[index].position - strlen(ri.WordArray[index].word));
			index++;
		}
		for (int i = 0; i < FSTARRAYSIZE; i++) {
			FST::FstDelete(FSTARRAY[i]);
		}
	}
}
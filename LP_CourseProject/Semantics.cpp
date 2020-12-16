#pragma once
#include "Semantics.h" 

namespace SM {
	void StartAnalysis(LT::LexTable lt, IT::IdTable it) {
		for (int i = 0; i < lt.size-1; i++) {
			if (lt.table[i].lexema[0] == '=') CheckTypes(lt, it, i);
			if (lt.table[i].lexema[0] == 'r') CheckRet(lt, it, i);
			if (it.table[lt.table[i].idxTI].idtype==IT::F && lt.table[i-1].lexema[0]!='f') isTrueParam(lt, it, i);
		}
	}
	void isTrueParam(LT::LexTable lt, IT::IdTable it, int index) {
		int parmamount=0;
		int i = 2;
		while (lt.table[index+i].lexema[0]!=')') {
			if (lt.table[index + i].lexema[0] == ',') {
				i++;
				continue;
			}
			parmamount++;
			if(it.table[lt.table[index+i].idxTI].iddatatype!= it.table[lt.table[index].idxTI+parmamount].iddatatype) 
				throw ERROR_THROW_IN(13, lt.table[index + i].sn, lt.table[index + i].cm);
			i++;
		}
		if (parmamount!= it.table[lt.table[index].idxTI].parmCount) 
			throw ERROR_THROW_IN(14, lt.table[index + i].sn, lt.table[index + i].cm);
	}
	void CheckTypes(LT::LexTable lt, IT::IdTable it, int index) {
		int j = 0;
		switch (it.table[lt.table[index - 1].idxTI].iddatatype) 
		{
		case LT::STR: {
			if (it.table[lt.table[index + 1].idxTI].iddatatype != LT::STR) throw ERROR_THROW_IN(12, lt.table[index + j].sn, lt.table[index + j].cm); break;
		}
		case LT::INT: {
			for (int j = index; lt.table[j + 1].lexema[0] != ';'; j++) {
				if ((lt.table[j + 1].lexema[0]== 'i' || lt.table[j + 1].lexema[0] == 'l') && it.table[lt.table[j + 1].idxTI].iddatatype != LT::INT)
					throw ERROR_THROW_IN(12, lt.table[j].sn, lt.table[j].cm);
				if (lt.table[j + 1].lexema[0]=='v' && (lt.table[j + 1].oper[0]!='+'&& lt.table[j + 1].oper[0] != '-' && lt.table[j + 1].oper[0] != '/' && lt.table[j + 1].oper[0] != '*'))
					throw ERROR_THROW_IN(12, lt.table[j].sn, lt.table[j].cm);
			}
			break;
		}
		}
	}

	void CheckRet(LT::LexTable lt, IT::IdTable it, int index) {
		int i = index;
		while (lt.table[i].lexema[0] != 'f') i--;
		i++;
		if (it.table[lt.table[i].idxTI].iddatatype != it.table[lt.table[index + 1].idxTI].iddatatype)
			throw ERROR_THROW_IN(15, lt.table[index].sn, lt.table[index].cm);
	}
}
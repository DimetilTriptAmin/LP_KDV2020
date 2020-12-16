#pragma once
#include "Error.h"
#include "IT.h"

namespace SM {
	void StartAnalysis(LT::LexTable, IT::IdTable);
	//проверка на диапазон  int -32768 to 32767
	//усечение переменных до ID_MAXSIZE		15
	//проверка функции галоҐна€
	void isTrueParam(LT::LexTable lt, IT::IdTable it, int index); // параметры в объ€влении того же типа, что и параметры при вызове, одинаковое количество
	void CheckRet(LT::LexTable lt, IT::IdTable it, int index);//return того же типа что и функци€
	void CheckTypes(LT::LexTable lt, IT::IdTable it, int index); //левый операнд того же типа что и правый
}
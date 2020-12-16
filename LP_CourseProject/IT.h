#pragma once
#define ID_MAXSIZE		15			// Макс. кол-во символов в идентификаторе
#define TI_MAXSIZE		4096		// Макс. кол-во строк в таблице идентификаторов
#define TI_INT_DEFAULT	0x00000000  // Значение по умолчанию для типа integer
#define TI_STR_DEFAULT	0x00		// Значение по умолчанию для типа string
#define TI_NULLIDX		0xffffffff  // Нет элемента таблицы идентификаторов
#define TI_STR_MAXSIZE	255			//

#include "LT.h"

namespace IT // таблица идентификаторов 
{
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4 };		// типы идентификаторов: переменная, функция, параметр, литерал

	struct Entry {
		int			parmCount=0;
		int			idxfirstLE= TI_NULLIDX;	// индекс первой строки в таблице лексем
		char		id[ID_MAXSIZE + 1] = "";	// идентификатор (автоматически усекается до ID_MAXSIZE)
		char		prefix[ID_MAXSIZE + 1] = "";// идентификатор (автоматически усекается до ID_MAXSIZE)
		LT::IDDATATYPE	iddatatype;				// тип данных
		IDTYPE		idtype;					// тип идентификатора
		union
		{
			int vint;							// значение integer
			bool vbool;							// значение integer
			struct {
				char len;						// количество символов в string
				char str[TI_STR_MAXSIZE - 1];	// символы string
			}	vstr;//[TI_STR_MAXSIZE];			// значение string
		} value;	// значение идентификатора
	};
	struct IdTable {
		int maxsize;					//Емкость < TI_maxsize
		int size;						//текущий размер
		Entry* table = nullptr;			//массив строк таблицы идентификаторов
	};

	IdTable Create(	//создать таблицу идентификаторов
		int size // емкость таблицы < TI_MAXSIZE
	);

	void Add(		//Добавить строку в таблицу идентификаторов
		IdTable& idtable, //экземляр таблицы идентификаторов
		Entry entry	//строка таблицы идентификаторов
	);

	void AddLib(		//Добавить строку в таблицу идентификаторов
		IdTable& idtable //экземляр таблицы идентификаторов
	);

	Entry GetEntry(		// получить строку таблицы идентификаторов
		IdTable& idtable, // экземляр таблицы ид
		int n			// строка таблицы ид
	);

	int IsId(   // возврат: номер строки если есть, TI_NULLIDX(если нет)
		IdTable& idtable, // экземляр таблицы ид
		Entry entry // идентификатор
	);

	int IsLit(   // возврат: номер строки если есть, TI_NULLIDX(если нет)
		IdTable& idtable, // экземляр таблицы ид
		Entry entry // идентификатор
	);

	int BinToDec(In::Word word);

	int OctToDec(In::Word word);

	void IdFill(IdTable& idtable, LT::LexTable& lexemTable, In::IN code);
	void Delete(IdTable& idtable); // удалить таблицу лексем (освободить память)
}

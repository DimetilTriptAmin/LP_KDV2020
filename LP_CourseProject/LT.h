#pragma once
#define LEXEMA_FIXSIZE		1		// фиксированный размер лексемы
#define LT_MAXSIZE			4096	// максимальное количество строк в таблице лексем
#define LT_TI_NULLIDX		0xffffffff	// нет элемента в таблице ид
#define LEX_INTEGER			't'		// лексема дл€ цэлы
#define LEX_BOOL			't'		// лексема дл€ лаг≥чны
#define LEX_STRING			't'		// лексема дл€ радок
#define LEX_ID				'i'		// лексема дл€ идентификатора
#define LEX_LITERAL			'l'		// лексема дл€ литерала
#define LEX_FUNCTION		'f'		// лексема дл€ функцы€
#define LEX_DECLARE			'd'		// лексема дл€ аб'€в≥ць
#define LEX_RETURN			'r'		// лексема дл€ в€рнуць
#define LEX_PRINT			'p'		// лексема дл€ вывесц≥
#define LEX_SEMICOLON		';'		// лексема дл€ ;
#define LEX_COMMA			','		// лексема дл€ ,
#define LEX_LEFTBRACE		'{'		// лексема дл€ {
#define LEX_BRACELET		'}'		// лексема дл€ }
#define LEX_LEFTHESIS		'('		// лексема дл€ (
#define LEX_RIGHTHESIS		')'		// лексема дл€ )
#define LEX_BIGGER			'v'		// лексема дл€ >
#define LEX_BIGGEREQUAL		'v'		// лексема дл€ >=
#define LEX_SMALLER			'v'		// лексема дл€ <
#define LEX_SMALLEREQUAL	'v'		// лексема дл€ <=
#define LEX_EQUAL			'v'		// лексема дл€ ==
#define LEX_NOTEQUAL		'v'		// лексема дл€ !=
#define LEX_PLUS			'v'		// лексема дл€ +
#define LEX_MINUS			'v'		// лексема дл€ -
#define LEX_STAR			'v'		// лексема дл€ *
#define LEX_DIRSLASH		'v'		// лексема дл€ /
#define LEX_ASSIGN			'='		// лексема дл€ =
#define LEX_INCLUDE			'q'		// лексема дл€ уключыць
#define LEX_WHILE			'w'		// лексема дл€ пакуль
#define LEX_IF				'I'		// лексема дл€ кал≥
#define LEX_ELSE			'E'		// лексема дл€ ≥накш


#include "In.h"

namespace LT {
	enum IDDATATYPE { STR = 1, INT = 2, BOOL };
	struct Entry {						// строка таблицы лексем
		char lexema[LEXEMA_FIXSIZE];	//лексема
		int cm;
		int sn;							//номер строки в исходном тексте
		int idxTI= LT_TI_NULLIDX;		// индекс в таблице идентификаторов или LT_TINULLIDX
		IDDATATYPE type;
		char oper[3];
	};

	struct LexTable {
		int maxsize;				// емкость таблицы лексем
		int size;					// текущий размер таблицы лексем
		Entry* table;				// массив строк таблицы лексем
	};
	LexTable Create(				// создать таблицу лексем
		int size					// емкость таблицы лексем
	);
	void Add(
		LexTable& lextable,			// экземл€р таблицы лексем
		Entry entry					// строка таблицы лексем
	);
	Entry GetEntry(
		LexTable& lextable,			// экземпл€р таблицы лексем
		int n						// номер получаемой строки
	);

	void LexFill(LexTable& lexemTable, In::IN ri);
	void Delete(LexTable& lextable); // удалить таблицу лексем (освободить пам€ть)
}
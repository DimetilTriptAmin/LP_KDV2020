#pragma once
#define LEXEMA_FIXSIZE		1		// ������������� ������ �������
#define LT_MAXSIZE			4096	// ������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX		0xffffffff	// ��� �������� � ������� ��
#define LEX_INTEGER			't'		// ������� ��� ����
#define LEX_BOOL			't'		// ������� ��� ������
#define LEX_STRING			't'		// ������� ��� �����
#define LEX_ID				'i'		// ������� ��� ��������������
#define LEX_LITERAL			'l'		// ������� ��� ��������
#define LEX_FUNCTION		'f'		// ������� ��� �������
#define LEX_DECLARE			'd'		// ������� ��� ��'����
#define LEX_RETURN			'r'		// ������� ��� �������
#define LEX_PRINT			'p'		// ������� ��� �������
#define LEX_SEMICOLON		';'		// ������� ��� ;
#define LEX_COMMA			','		// ������� ��� ,
#define LEX_LEFTBRACE		'{'		// ������� ��� {
#define LEX_BRACELET		'}'		// ������� ��� }
#define LEX_LEFTHESIS		'('		// ������� ��� (
#define LEX_RIGHTHESIS		')'		// ������� ��� )
#define LEX_BIGGER			'v'		// ������� ��� >
#define LEX_BIGGEREQUAL		'v'		// ������� ��� >=
#define LEX_SMALLER			'v'		// ������� ��� <
#define LEX_SMALLEREQUAL	'v'		// ������� ��� <=
#define LEX_EQUAL			'v'		// ������� ��� ==
#define LEX_NOTEQUAL		'v'		// ������� ��� !=
#define LEX_PLUS			'v'		// ������� ��� +
#define LEX_MINUS			'v'		// ������� ��� -
#define LEX_STAR			'v'		// ������� ��� *
#define LEX_DIRSLASH		'v'		// ������� ��� /
#define LEX_ASSIGN			'='		// ������� ��� =
#define LEX_INCLUDE			'q'		// ������� ��� ��������
#define LEX_WHILE			'w'		// ������� ��� ������
#define LEX_IF				'I'		// ������� ��� ���
#define LEX_ELSE			'E'		// ������� ��� �����


#include "In.h"

namespace LT {
	enum IDDATATYPE { STR = 1, INT = 2, BOOL };
	struct Entry {						// ������ ������� ������
		char lexema[LEXEMA_FIXSIZE];	//�������
		int cm;
		int sn;							//����� ������ � �������� ������
		int idxTI= LT_TI_NULLIDX;		// ������ � ������� ��������������� ��� LT_TINULLIDX
		IDDATATYPE type;
		char oper[3];
	};

	struct LexTable {
		int maxsize;				// ������� ������� ������
		int size;					// ������� ������ ������� ������
		Entry* table;				// ������ ����� ������� ������
	};
	LexTable Create(				// ������� ������� ������
		int size					// ������� ������� ������
	);
	void Add(
		LexTable& lextable,			// �������� ������� ������
		Entry entry					// ������ ������� ������
	);
	Entry GetEntry(
		LexTable& lextable,			// ��������� ������� ������
		int n						// ����� ���������� ������
	);

	void LexFill(LexTable& lexemTable, In::IN ri);
	void Delete(LexTable& lextable); // ������� ������� ������ (���������� ������)
}
#pragma once
#define ID_MAXSIZE		15			// ����. ���-�� �������� � ��������������
#define TI_MAXSIZE		4096		// ����. ���-�� ����� � ������� ���������������
#define TI_INT_DEFAULT	0x00000000  // �������� �� ��������� ��� ���� integer
#define TI_STR_DEFAULT	0x00		// �������� �� ��������� ��� ���� string
#define TI_NULLIDX		0xffffffff  // ��� �������� ������� ���������������
#define TI_STR_MAXSIZE	255			//

#include "LT.h"

namespace IT // ������� ��������������� 
{
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4 };		// ���� ���������������: ����������, �������, ��������, �������

	struct Entry {
		int			parmCount=0;
		int			idxfirstLE= TI_NULLIDX;	// ������ ������ ������ � ������� ������
		char		id[ID_MAXSIZE + 1] = "";	// ������������� (������������� ��������� �� ID_MAXSIZE)
		char		prefix[ID_MAXSIZE + 1] = "";// ������������� (������������� ��������� �� ID_MAXSIZE)
		LT::IDDATATYPE	iddatatype;				// ��� ������
		IDTYPE		idtype;					// ��� ��������������
		union
		{
			int vint;							// �������� integer
			bool vbool;							// �������� integer
			struct {
				char len;						// ���������� �������� � string
				char str[TI_STR_MAXSIZE - 1];	// ������� string
			}	vstr;//[TI_STR_MAXSIZE];			// �������� string
		} value;	// �������� ��������������
	};
	struct IdTable {
		int maxsize;					//������� < TI_maxsize
		int size;						//������� ������
		Entry* table = nullptr;			//������ ����� ������� ���������������
	};

	IdTable Create(	//������� ������� ���������������
		int size // ������� ������� < TI_MAXSIZE
	);

	void Add(		//�������� ������ � ������� ���������������
		IdTable& idtable, //�������� ������� ���������������
		Entry entry	//������ ������� ���������������
	);

	void AddLib(		//�������� ������ � ������� ���������������
		IdTable& idtable //�������� ������� ���������������
	);

	Entry GetEntry(		// �������� ������ ������� ���������������
		IdTable& idtable, // �������� ������� ��
		int n			// ������ ������� ��
	);

	int IsId(   // �������: ����� ������ ���� ����, TI_NULLIDX(���� ���)
		IdTable& idtable, // �������� ������� ��
		Entry entry // �������������
	);

	int IsLit(   // �������: ����� ������ ���� ����, TI_NULLIDX(���� ���)
		IdTable& idtable, // �������� ������� ��
		Entry entry // �������������
	);

	int BinToDec(In::Word word);

	int OctToDec(In::Word word);

	void IdFill(IdTable& idtable, LT::LexTable& lexemTable, In::IN code);
	void Delete(IdTable& idtable); // ������� ������� ������ (���������� ������)
}

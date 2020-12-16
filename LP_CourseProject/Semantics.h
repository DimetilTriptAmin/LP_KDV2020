#pragma once
#include "Error.h"
#include "IT.h"

namespace SM {
	void StartAnalysis(LT::LexTable, IT::IdTable);
	//�������� �� ��������  int -32768 to 32767
	//�������� ���������� �� ID_MAXSIZE		15
	//�������� ������� �������
	void isTrueParam(LT::LexTable lt, IT::IdTable it, int index); // ��������� � ���������� ���� �� ����, ��� � ��������� ��� ������, ���������� ����������
	void CheckRet(LT::LexTable lt, IT::IdTable it, int index);//return ���� �� ���� ��� � �������
	void CheckTypes(LT::LexTable lt, IT::IdTable it, int index); //����� ������� ���� �� ���� ��� � ������
}
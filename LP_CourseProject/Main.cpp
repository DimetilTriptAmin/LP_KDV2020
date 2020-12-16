#include <tchar.h>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "FST.h"
#include "OUT.h"
#include "MFST.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Semantics.h"
#include "CodeGen.h"

using namespace std;

void ViewLexem(LT::LexTable lextable, Log::LOG log) {
	LT::Entry newLexem;
	int curLine = 0;
	for (int j = 0; j < lextable.size; j++) {
		newLexem = LT::GetEntry(lextable, j);
		if (curLine == newLexem.sn) {
			*log.stream << newLexem.lexema[0];
		}
		else if (newLexem.sn < 10) {
			*log.stream << endl << '0' << newLexem.sn << "  " << newLexem.lexema[0];
		}
		else {
			*log.stream << endl << newLexem.sn << "  " << newLexem.lexema[0];
		}
		curLine = newLexem.sn;
	}
}
void ViewId(IT::IdTable idtable, Log::LOG log) {
	IT::Entry newId;
	for (int j = 0; j < idtable.size; j++) {
		newId = IT::GetEntry(idtable, j);
		switch (newId.idtype)
		{
		case 1:
			*log.stream << "���������� " << newId.prefix << ':' << newId.id << " ���� ";
			switch (newId.iddatatype)
			{
			case LT::INT:*log.stream << "����" << endl; break;
			case LT::STR:*log.stream << "�����" << endl; break;
			case LT::BOOL:*log.stream << "������" << endl; break;
			default:
				break;
			}
			break;
		case 2:
			*log.stream << "������� " << newId.prefix << ':' << newId.id << " ���� ";
			switch (newId.iddatatype)
			{
			case LT::INT:*log.stream << "����" << endl; break;
			case LT::STR:*log.stream << "�����" << endl; break;
			case LT::BOOL:*log.stream << "������" << endl; break;
			default:
				break;
			}
			break;
		case 3:
			*log.stream << "�������� " << newId.prefix << ':' << newId.id << " ���� ";
			switch (newId.iddatatype)
			{
			case LT::INT:*log.stream << "����" << endl; break;
			case LT::STR:*log.stream << "�����" << endl; break;
			case LT::BOOL:*log.stream << "������" << endl; break;
			default:
				break;
			}
			break;
		case 4:
			*log.stream << "˳����� ���� ";
			if (newId.iddatatype == 1) *log.stream << "����� �� ��������� " << newId.value.vstr.str << endl;
			else if (newId.iddatatype == 2) *log.stream << "���� �� ��������� " << newId.value.vint << endl;

			break;
		default:
			break;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "ru");


	Log::LOG log = Log::INITLOG;
	char test[] = "����:";
	char without[] = "��� �������";
	char with[] = "� ��������";

	try
	{
		system("chcp 1251");

		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << L"-in: " << parm.in << L"  -out: " << parm.out << L"  -log: " << parm.log << endl << endl;
		In::IN in = In::getin(parm.in);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, test, without, "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		Log::WriteIn(log, in);
		Log::WriteAnalys(log, in);
		LT::LexTable lexemTable = LT::Create(in.WordAmount);
		IT::IdTable IdTable = IT::Create(in.WordAmount);
		LT::LexFill(lexemTable, in);
		if (lexemTable.table[0].lexema[0] == LEX_INCLUDE) IT::AddLib(IdTable);
		IT::IdFill(IdTable, lexemTable, in);

		Out::OUT out = Out::getout(parm.out);

		*log.stream << "--- ������ ������ ---" << endl;
		cout << "������ ������ ���������� ���������" << endl;
		ViewLexem(lexemTable, log);
		*log.stream << endl;
		*log.stream << "--- ������ �������������� ---" << endl;
		cout << "������ �������������� ���������� ���������" << endl;
		ViewId(IdTable, log);
		*log.stream << endl;

		lexemTable.table[lexemTable.size].lexema[0] = '$';
		lexemTable.size++;

		MFST::Mfst mfst(lexemTable, GRB::getGreibach());
		/*for (int i = 0; i < mfst.lenta_size; i++) {
			cout << (char)mfst.lenta[i];
		}*/
		//MFST_TRACE_START;
		mfst.start();
		mfst.savededucation();
		*log.stream << "--- ����� ������� ---" << endl;
		mfst.printrules(log);

		SM::StartAnalysis(lexemTable,IdTable);
		cout << "���������� ����� �������� ��� �������" << endl;

		CG::Compile(IdTable, lexemTable, out);
		cout << "��������� ���� �������� ��� �������" << endl;

		cout << endl;
		Out::Close(out);
		Log::Close(log);
		system("pause");
	}
	catch (Error::ERROR e) {
		cout << endl;
		if (e.id == 100) {
			cout << "������� " << e.id << ":" << e.message << endl << endl;
			log = Log::getlog(FAST_LOG);
			Log::WriteLine(log, test, with, "");
			Log::WriteLog(log);
			Log::WriteError(log, e);
			system("pause");
			return 0;
		}
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, test, with, "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		Log::WriteError(log, e);
		Log::Close(log);
		cout << "������� " << e.id << ":" << e.message << endl << endl;
		if (e.inext.line != -1)
			cout << "����� " << e.inext.line << endl << "������: " << e.inext.col << endl << endl;
		system("pause");
	}
	return 0;
}
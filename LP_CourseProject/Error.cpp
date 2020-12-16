#include "Error.h"
namespace Error {
	ERROR errors[ERROR_MAX_ENTRY] = {
		ERROR_ENTRY(0,  "������������� ��� ������"),
		ERROR_ENTRY(1,  "ѳ������ ����"),
		ERROR_ENTRY(2,  "��������� ���������� �������"),
		ERROR_ENTRY(3,  "�� ���������� ���������� ��� ��������������"),
		ERROR_ENTRY(4,  "�� ���������� ���������� ��� �������� ��������������"),
		ERROR_ENTRY(5,  "����������� ������ ������"),
		ERROR_ENTRY(6,  "����������� ������ ��������������"),
		ERROR_ENTRY(7,  "������� ������������ �������"),
		ERROR_ENTRY(8,  "������������� ������� �� ���������"),
		ERROR_ENTRY(9,  "�� ���������� ���������� ������ ������"),
		ERROR_ENTRY(10, "˳����� ���� '����' �������� ����������"),
		ERROR_ENTRY(11, "���������� ��� ��'������"),
		ERROR_ENTRY(12, "�������������� ����"),
		ERROR_ENTRY(13, "�������������� ���� ���������"),
		ERROR_ENTRY(14, "�������������� ��������� ���������"),
		ERROR_ENTRY(15, "���, �� ��������� ������ ���������� ���� �������"),
		ERROR_ENTRY(16, "�� ��������� ������� �������"),
		ERROR_ENTRY(17, "������� ��� ��'������"),
		ERROR_ENTRY_NODEF(18),ERROR_ENTRY_NODEF(19),
		ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30),
		ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),
		ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "��������� -in ������ ���� ����������"),
		ERROR_ENTRY(101, "������ ���������� ��������� ����� ������"),
		ERROR_ENTRY(102, "������� ��� �������� ����� � �������� �����(-in)"),
		ERROR_ENTRY(103, "������������� ���� � �������� ����� (-in)"),
		ERROR_ENTRY(104, "������� ��� �������� ��������� (-log)"),
		ERROR_ENTRY(105, "������� ��� �������� ��������� ����� (-out)"),
		ERROR_ENTRY(106, "������� ��� �������� ��������"),
		ERROR_ENTRY_NODEF(107),ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110,"����������� ��������� ��������"),
		ERROR_ENTRY(111, "��������� ��������"),
		ERROR_ENTRY(112, "������� � ������"),
		ERROR_ENTRY(113, "������� � ���������� �������"),
		ERROR_ENTRY(114, "������� � ���������� ��������� �������"),
		ERROR_ENTRY_NODEF10(110),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160),
		ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY_NODEF100(600),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900),
	};
	ERROR geterror(int id) {
		ERROR err;
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			err = errors[id];
		}
		else {
			err = errors[0];
		}
		return err;
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		ERROR err;
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			err = errors[id];
			err.inext.col = col;
			err.inext.line = line;
		}
		else {
			err = errors[0];
		}
		return err;
	}
}
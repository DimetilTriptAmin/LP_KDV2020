#include "CodeGen.h"
#include <fstream>
#include "Error.h"

namespace CG {
	void Compile(IT::IdTable it, LT::LexTable lt, Out::OUT out) {
		bool isDec = false;
		bool isCast = false;
		bool isInt = false;
		bool isFunc = false;
		char buff[7];
		*out.stream << CSUSING << CSSTARTING;
		for (int i = 0; i < lt.size; i++) {
			if (i != 0 && lt.table[i].sn != lt.table[i - 1].sn) {
				*out.stream << '\n';
			}
			switch (lt.table[i].lexema[0])
			{
			case LEX_LEFTBRACE: {
				isFunc = false;
				*out.stream << '{';
				break;
			}
			case LEX_INCLUDE: {
				char buff[255];
				char l[255];
				char sys[255] = "рэсурсы/бібліятэцы/";
				strncpy(l, &(it.table[lt.table[i + 1].idxTI].value.vstr.str[1]), strlen(it.table[lt.table[i + 1].idxTI].value.vstr.str) - 2);
				l[strlen(it.table[lt.table[i + 1].idxTI].value.vstr.str)-2] = '\0';
				std::ifstream lib(strcat(sys,l));
				if (!lib.is_open()) throw ERROR_THROW(106);
				while (!lib.eof())
				{
					lib.getline(buff, 255);
					*out.stream << buff << '\n';
				}
				i++;
				break;
			}
			case LEX_ID: {
				if (isFunc || isDec || (it.table[lt.table[i].idxTI].idtype == IT::P && isFunc)) {
					switch (it.table[lt.table[i].idxTI].iddatatype)
					{
					case LT::INT: if (it.table[lt.table[i].idxTI].idtype == IT::F && !strcmp(it.table[lt.table[i].idxTI].id, "галоўная")) *out.stream << "int ";
								else*out.stream << CSINT; break;
					case LT::STR: *out.stream << CSSTR; break;
					case LT::BOOL: *out.stream << CSBOOL; break;
					default:
						break;
					}
					isDec = false;
				}
				if (it.table[lt.table[i].idxTI].iddatatype == LT::INT)isInt = true;
				else isInt = false;
				if (it.table[lt.table[i].idxTI].idtype==IT::F && !strcmp(it.table[lt.table[i].idxTI].id,"галоўная")) *out.stream << "Main";
				else *out.stream << it.table[lt.table[i].idxTI].id;
				break;
			}
			case LEX_WHILE: {
				*out.stream << CSWHILE;
				break;
			}
			case LEX_SEMICOLON: {
				if (isCast) {
					*out.stream << ')';
					isCast = false;
				}
				*out.stream << ';';
				break;
			}
			case LEX_ASSIGN: {
				*out.stream << '=';
				if (isInt) {
					*out.stream << CSEXPL;
					isCast = true;
					isInt = false;
				}
				break;
			}
			case LEX_IF: {
				*out.stream << CSIF;
				break;
			}
			case LEX_ELSE: {
				*out.stream << CSELSE;
				break;
			}
			case LEX_INTEGER: {
				break;
			}
			case LEX_LITERAL: {
				if (it.table[lt.table[i].idxTI].iddatatype == LT::INT)
					*out.stream << _itoa(it.table[lt.table[i].idxTI].value.vint, buff, 10);
				else if (it.table[lt.table[i].idxTI].iddatatype == LT::BOOL) {
					if (it.table[lt.table[i].idxTI].value.vbool) *out.stream << CSTRUE;
					else *out.stream << CSFALSE;
				}
				else
					*out.stream << it.table[lt.table[i].idxTI].value.vstr.str;
				break;
			}
			case LEX_FUNCTION: {
				*out.stream << CSSTATIC << CSPUBLIC;
				isFunc = true;
				break;
			}
			case LEX_DECLARE: {
				isDec = true;
				break;
			}
			case LEX_PRINT: {
				*out.stream << CSOUT;
				break;
			}
			case LEX_RETURN: {
				*out.stream << CSRET;
				break;
			}
			case LEX_BIGGER: {
				*out.stream << lt.table[i].oper;
				break;
			}
			case '$': {
				break;
			}
			default: {
				*out.stream << lt.table[i].lexema[0];
				break;
			}
			}
		}
		*out.stream << '}' << '\n' <<'}';
	}
}
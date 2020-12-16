#pragma once
#include "IT.h"
#include "Out.h"

#define CSSTATIC		"static "
#define CSPUBLIC		"public "
#define CSFUNC			"function "
#define CSINT			"short "
#define CSEXPL			"(short)("
#define CSSTR			"string "
#define CSBOOL			"bool "
#define CSWHILE			"while"
#define CSRET			"return "
#define CSOUT			"Console.WriteLine"
#define CSTRUE			"true"
#define CSFALSE		    "false"
#define CSIF		    "if"
#define CSELSE		    "else"
#define CSUSING			"using System;\n\
using System.Collections;\n\
using System.Collections.Generic;\n\
using System.Text;\n"
#define CSSTARTING		"namespace KDV2020\n\
{\n\
class KDV2020Program\
{\n"

namespace CG {
	void Compile(IT::IdTable it, LT::LexTable lt, Out::OUT out);
}
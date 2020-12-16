#pragma once
#include "Parm.h"
#include "In.h"

#define MAX_LINE_SIZE 1024

namespace Out
{
	struct OUT
	{
		wchar_t outfile[PARM_MAX_SIZE];
		std::ofstream* stream;
	};

	OUT getout(wchar_t outfile[]);
	void WriteLine(OUT out, char* c);
	void WriteLine(OUT out, wchar_t* c, ...);
	void Close(OUT out);
}
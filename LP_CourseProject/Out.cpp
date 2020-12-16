#include <fstream>
#include "Out.h"
#include "Error.h"

namespace Out
{
	OUT getout(wchar_t outfile[])
	{
		OUT re = {};
		re.stream = new std::ofstream(outfile);
		wcscpy_s(re.outfile, outfile);

		if (!re.stream->is_open()) throw ERROR_THROW(105);

		return re;
	}

	void WriteLine(OUT out, char* c)
	{
			*out.stream << c;
			*out.stream << "\n";
	}

	void WriteLine(OUT out, wchar_t* c, ...)
	{
		wchar_t** ptr = &c;
		while (*ptr != L"")
		{
			char tmp[MAX_LINE_SIZE];
			size_t tsize = 0;
			wcstombs_s(&tsize, tmp, *ptr, MAX_LINE_SIZE);
			*out.stream << tmp;
			ptr++;
		}
	}

	void Close(OUT out)
	{
		out.stream->close();
		delete out.stream;
	}
}
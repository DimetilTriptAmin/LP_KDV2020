#pragma once
#include <fstream>
#define LT_MAXSIZE			4096	// максимальное количество строк в таблице лексем
#define SIZE				1024
#define IN_MAX_LEN_TEXT		1024*1024
#define IN_CODE_ENDL		'\n'
#define IN_CODE_TABLE		{\
							/*0  */IN::D, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T,   ' ',   '|', IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*16 */IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*32 */IN::D, IN::D, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::D, IN::D, IN::D, IN::D, IN::D, IN::T, IN::T, IN::D, \
							/*48 */IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::D, IN::D, IN::D, IN::D, IN::T, \
							/*64 */IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*80 */IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*96 */IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*112*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::D, IN::T, IN::D, IN::T, IN::T, \
																																				   \
							/*128*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*144*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*160*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*176*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*192*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*208*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*224*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
							/*240*/IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
					}

namespace In {

	struct Word {
		int line;
		int position;
		char* word;
	};

	struct IN {
		enum { T = 1024, F = 2048, I = 4096, D = 8192 };
		int size = 0;
		int lines = 0;
		int ignor = 0;
		unsigned char* text;
		int code[256] = IN_CODE_TABLE;
		Word WordArray[LT_MAXSIZE];
		int WordAmount = 0;
	};

	Word CreateWord(int size, IN table, int curLine, int curCol);
	void addWord(IN* table, Word entry);
	IN getin(wchar_t infile[]);
}
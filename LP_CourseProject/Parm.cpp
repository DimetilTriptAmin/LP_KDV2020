#include "Parm.h"
#include "Error.h"
#include <iostream>

namespace Parm {
	PARM getparm(int argc, _TCHAR* argv[]) {
		PARM prm;
		wchar_t buff;
		bool if_In = false;
		if (argc == 1) throw ERROR_THROW(100);
		for (int i = 1; i < argc; i++) {
			buff = argv[i][1];
			switch (buff) {
			case 'i': wcscpy_s(prm.in, &argv[i][wcslen(PARM_IN) + 1]);
				if (prm.out[0] == 0xcccc) { wcscpy_s(prm.out, &argv[i][wcslen(PARM_IN) + 1]);  wcscat_s(prm.out, PARM_OUT_DEFAULT_EXT); }
				if (prm.log[0] == 0xcccc) { wcscpy_s(prm.log, &argv[i][wcslen(PARM_IN) + 1]);  wcscat_s(prm.log, PARM_LOG_DEFAULT_EXT); }
				if_In = true; break;
			case 'o': wcscpy_s(prm.out, &argv[i][wcslen(PARM_OUT) + 1]); break;
			case 'l': wcscpy_s(prm.log, &argv[i][wcslen(PARM_LOG) + 1]); break;
			}
		}
		if (!if_In) throw ERROR_THROW(100);
		return prm;
	}
}
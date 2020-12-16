#include "Log.h"
#include "FST.h"
namespace Log
{
    LOG getlog(wchar_t logfile[]) {
        LOG myLog;
        myLog.stream = new std::ofstream;
        myLog.stream->open(logfile);
        if (!myLog.stream->is_open()) throw ERROR_THROW(104);
        wcscpy_s(myLog.logfile, logfile);
        return myLog;
    }

    LOG getlog(const wchar_t* logfile) {
        LOG myLog;
        myLog.stream = new std::ofstream;
        myLog.stream->open(logfile);
        if (!myLog.stream->is_open()) throw ERROR_THROW(104);
        wcscpy_s(myLog.logfile, logfile);
        return myLog;
    }

    void WriteLine(LOG log, char* c, ...) {
        char** pChar = &c;
        while (*pChar != "") {
            *log.stream << *pChar;
            pChar++;
        }
        *log.stream << std::endl;
    }

    void WriteLine(LOG log, wchar_t* c, ...) {
        wchar_t** pChar = &c;
        while (*pChar != L"") {
            char buff[SIZE];
            size_t tsize = 0;
            wcstombs_s(&tsize, buff, *pChar, SIZE);
            *log.stream << buff;
            pChar++;
        }
        *log.stream << std::endl;
    }

    void WriteLog(LOG log) {
        char date[100];
        tm local;
        time_t currentTime;
        currentTime = time(NULL);
        localtime_s(&local, &currentTime);
        strftime(date, 100, "%d.%m.%Y %H:%M:%S", &local);
        *log.stream << "--- Пратакол --- \nДата: " << date << std::endl;
    }
    void WriteParm(LOG log, Parm::PARM parm) {
        char buff[PARM_MAX_SIZE];
        size_t tsize = 0;
        *log.stream << "--- Параметры --- " << std::endl;
        wcstombs_s(&tsize, buff, parm.in, PARM_MAX_SIZE);
        *log.stream << "-in : " << buff << std::endl;
        wcstombs_s(&tsize, buff, parm.out, PARM_MAX_SIZE);
        *log.stream << "-out: " << buff << std::endl;
        wcstombs_s(&tsize, buff, parm.log, PARM_MAX_SIZE);
        *log.stream << "-log: " << buff << std::endl;
    }
    void WriteIn(LOG log, In::IN in) {
        *log.stream << "--- Зыходныя дадзеныя --- " << std::endl;
        *log.stream << "Колькасць знакаў : " << in.size << std::endl;
        *log.stream << "Колькасць радкоў    : " << in.lines << std::endl;
    }
    void WriteAnalys(LOG log, In::IN in) {
        *log.stream << "--- Аналіз --- " << std::endl;
    }
    void WriteError(LOG log, Error::ERROR error) {
        *log.stream << "--- Памылка --- " << std::endl;
        *log.stream << "Памылка " << error.id << ":" << error.message << std::endl;
        if (error.inext.line != -1)
            *log.stream << "Радок " << error.inext.line << std::endl << "Пазіцыя: " << error.inext.col << std::endl << std::endl;
    }
    void Close(LOG log) {
        log.stream->close();
        delete log.stream;
    }
}
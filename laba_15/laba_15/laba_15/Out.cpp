#include "stdafx.h"
#pragma warning(disable:4996)

namespace Out
{
	OUT getout(wchar_t outfile[])
	{
		OUT out;
		out.stream = new ofstream;
		out.stream->open(outfile);
		if (!out.stream->is_open())
		{
			throw ERROR_THROW(112);
		}
		wcscpy_s(out.outfile, outfile);

		return out;
	}

	void WriteLine(OUT out, char* c, ...)
	{
		char** pc = &c;
		int i = 0;
		while (*pc != "")
		{
			*out.stream << pc;
			*pc++;
		}
		*out.stream << endl;
	}

	void WriteLine(OUT out, wchar_t* c, ...)
	{
		wchar_t** pc = &c;
		char l[1024] = "";
		char f[1024] = "";
		while (*pc != L"")
		{
			wcstombs_s(0, l, *pc, IN_MAX_LEN_TEXT);
			strcat_s(f, l);
			pc++;
		}
		*out.stream << f;
	}

	void WriteOut(OUT out) {
		char date[100];
		tm local;
		time_t currentTime;
		currentTime = time(NULL);
		localtime_s(&local, &currentTime);
		strftime(date, 100, "%d.%m.%Y %H:%M:%S", &local);
		*out.stream << "--- Протокол --- Дата: " << date << endl;
	}

	void WriteParm(OUT out, Parm::PARM parm) {

		char buff[PARM_MAX_SIZE];
		size_t tsize = 0;

		*out.stream << "---- Параметры ------" << endl;
		wcstombs_s(&tsize, buff, parm.log, PARM_MAX_SIZE);
		*out.stream << "-log: " << buff << endl;
		wcstombs_s(&tsize, buff, parm.out, PARM_MAX_SIZE);
		*out.stream << "-out: " << buff << endl;
		wcstombs_s(&tsize, buff, parm.in, PARM_MAX_SIZE);
		*out.stream << "-in: " << buff << endl;
	}

	void WriteIn(OUT out, In::IN in)
	{
		*out.stream << "---- Исходные данные ------" << endl;
		*out.stream << "Количество символов: " << in.size << endl;
		*out.stream << "Проигнорированно   : " << in.ignore << endl;
		*out.stream << "Количество строк   : " << in.lines << endl;
	}

	void WriteError(OUT out, Error::ERROR error)
	{

		*out.stream << "--- Ошибки --- " << endl;
		*out.stream << "Ошибка " << error.id << ":" << error.message << endl;

		if (error.inext.line != -1)
		{
			*out.stream << "Строка " << error.inext.line << " Символ: " << error.inext.col << endl << endl;
		}
	}

	void Close(OUT out)
	{
		out.stream->close();
		delete out.stream;
	}
}
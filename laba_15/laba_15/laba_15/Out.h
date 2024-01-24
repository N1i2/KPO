#pragma once
#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include "Parm.h"

namespace Out
{
	struct OUT
	{
		wchar_t outfile[PARM_MAX_SIZE];
		std::ofstream* stream;
	};

	static const OUT INITOUT{ L"", NULL };		 // структура для начальной инициализации OUT
	OUT getout(wchar_t outfile[]);				 // сформировать структуру OUT
	void WriteLine(OUT out, char* c, ...);		 // вывести в протокол конкатенацию строк
	void WriteLine(OUT out, wchar_t* с, ...);	 // вывести в протокол конкатенацию строк
	void WriteOut(OUT out);						 // вывести в протокол заголовок
	void WriteParm(OUT out, Parm::PARM parm);	 // вывести в протокол информацию о входных параметрах
	void WriteIn(OUT out, In::IN in);			 // вывести в протокол информацию о входном потоке
	void WriteError(OUT out, Error::ERROR error);// вывести в протокол информацию об ошибке
	void Close(OUT out);						 // закрытие потока
}

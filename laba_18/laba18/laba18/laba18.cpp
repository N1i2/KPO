#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	std::cout << "--------------------------------getparm----------------------------------" << std::endl;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		std::wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << std::endl << std::endl;
	}
	catch (Error::ERROR e)
	{
		std::cout << "ID: " << e.id << " Сообщение: " << e.message << " Строка: " << e.inext.line << " Позиция:" << e.inext.col << std::endl;
	}

	std::cout << "---------------------------------getin-----------------------------------" << std::endl;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		std::cout << "Всего символов: " << in.size << std::endl;
		std::cout << "Всего строк: " << in.lines << std::endl;
		std::cout << "Пропущено: " << in.ignor << std::endl;
	}
	catch (Error::ERROR e)
	{
		std::cout << "ID: " << e.id << " Сообщение: " << e.message << " Строка: " << e.inext.line << " Позиция:" << e.inext.col << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------" << std::endl;

	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		out = Out::getout(parm.out);
		Log::WriteLine(log, "Тест: ", "без ошибок ", "");
		Log::WriteLine(log, L"Тест: ", L"без ошибок\n ", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Out::WriteIn(out, in);
		LT::LexTable lexTable;
		IT::IdTable	idTable;

		LA::FindLex(in, lexTable, idTable);

		lexTable.PrintLexTable(L"..\\x64\\Debug\\TableOfLexems.txt");
		idTable.PrintIdTable(L"..\\x64\\Debug\\TableOfIdentificators.txt");

		MFST_TRACE_START										//отладка
			MFST::Mfst mfst(lexTable, GRB::getGreibach());		//автомат
		mfst.start();											// старт синтаксического анализа

		mfst.savededucation();									//сохранить правила вывода

		mfst.printrules();										//отладка: вывести правила вывода

		LT::Delete(lexTable);
		IT::Delete(idTable);
		Log::Close(log);
		Out::Close(out);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
		Out::WriteError(out, e);
	}
	system("pause");
	return 0;
}
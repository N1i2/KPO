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

	static const OUT INITOUT{ L"", NULL };		 // ��������� ��� ��������� ������������� OUT
	OUT getout(wchar_t outfile[]);				 // ������������ ��������� OUT
	void WriteLine(OUT out, char* c, ...);		 // ������� � �������� ������������ �����
	void WriteLine(OUT out, wchar_t* �, ...);	 // ������� � �������� ������������ �����
	void WriteOut(OUT out);						 // ������� � �������� ���������
	void WriteParm(OUT out, Parm::PARM parm);	 // ������� � �������� ���������� � ������� ����������
	void WriteIn(OUT out, In::IN in);			 // ������� � �������� ���������� � ������� ������
	void WriteError(OUT out, Error::ERROR error);// ������� � �������� ���������� �� ������
	void Close(OUT out);						 // �������� ������
}

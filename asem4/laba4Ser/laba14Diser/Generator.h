#pragma once
#include<fstream>
#include<list>

namespace Generator
{
	using namespace std;
#define ASM_START \
<< ".586P" << endl \
<< ".MODEL FLAT, STDCALL" << endl \
<< "includelib kernel32.lib" << endl << endl\
<< "ExitProcess PROTO : DWORD" << endl\
<< "MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD" << endl << endl\
<< ".STACK 4096" << endl << endl\
<< ".CONST" << endl << endl \
<< ".DATA" << endl << endl \
<< "MB_OK\tEQU 0" << endl\
<< "STR1\tDB \"Программа\", 0" << endl\
<< "HW\t\tDD ?" << endl

#define ASM_END \
<< ".CODE" << endl << endl \
<< "main PROC" << endl << endl \
<< "START: " << endl\
<< "\tpush 0" << endl \
<< "\tcall ExitProcess" << endl \
<< "main ENDP" << endl\
<< "end main" << endl

	void getGenerator(list<short> allShort, list<unsigned short> allUshort);
}
#include<iostream>
#include<fstream>
#include"Generator.h"
#include"stdafx.h"

namespace Generator
{
	void getGenerator(std::list<short> allShort, std::list<unsigned short> allUshort)
	{

		std::ofstream file;
		file = std::ofstream("..\\..\\file.asm");

		file ASM_START;
		int i = 0;

		for(const auto& elem:allShort)
			file << "sh" << (i++) << " DW " << elem << endl;
		i = 0;

		for (const auto& elem : allUshort)
			file << "ush" << (i++) << " DW " << elem << endl;

		file ASM_END;
	}
}
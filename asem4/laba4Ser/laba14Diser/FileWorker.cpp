#include"stdafx.h"

namespace FileDiser
{
	std::list<short> GetShort()
	{
		std::list<short> values;
		std::ifstream file(path);
		std::string helpS;

		if (!file.eof())
		{
			while (std::getline(file, helpS))
				if (helpS[0] == dataShort)
					values.push_back(std::stoi(helpS.substr(2)));
		}
		else
			std::cout << "Error whith file" << std::endl;

		if (values.size() == 0)
		{
			std::cout << "There aren't SHORT numbers in this file" << std::endl;
			return values;
		}

		return values;
	}

	std::list<unsigned short> getUshort()
	{
		std::list<unsigned short> values;
		std::ifstream file(path);
		std::string helpS;

		if (file.is_open())
		{
			while (std::getline(file, helpS))
				if (helpS[0] == dataUshort)
					values.push_back(std::stoi(helpS.substr(2)));
		}
		else
			std::cout << "Error whith file" << std::endl;

		if (values.size() == 0)
		{
			std::cout << "There aren't USHORT numbers in this file" << std::endl;
			return values;
		}

		return values;
	}
}
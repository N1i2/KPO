#include"stdafx.h"

namespace MyFile
{
	void serialize(std::string& datas)
	{
		std::string errorNumb = "Tis is not a number";
		std::string errorOpen = "File is not open";

		char* check;
		long data = std::strtol(datas.c_str(), &check, 10);
		bool type = false;
		short n1;
		unsigned short n2;

		if (!(check != datas.c_str() && *check == '\0'))
			throw errorNumb;

		if (data < std::numeric_limits<short>::max())
			type = true;

		std::stringstream str;
		std::stringstream val;

		std::string dataText = "";
		dataText += (type) ? dataShort : dataUshort;

		if (type)
		{
			n1 = data;

			str << sizeof(n1);
			dataText += str.str();

			val << n1;
			dataText += val.str();
		}
		else 
		{
			n2 = data;

			str << sizeof(n2);
			dataText += str.str();

			val << n2;
			dataText += val.str();
		}

		dataText += '\n';

		std::ofstream file(path, std::ios::app, std::ios::binary);

		if (file.is_open())
		{
			//file.write(reinterpret_cast<const char*>(dataText.c_str()), dataText.size());
			for(int i =0 ;i < dataText.length(); i++)
				file.write((char*)&dataText[i], 1);

			file.close();
		}
		else
			throw errorOpen;
	}

	void ClearFile()
	{
		std::ofstream file(path);

		file.write("", 0);
	}
}
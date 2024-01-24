#include"stdafx.h"

int main()
{	
	MyFile::ClearFile();

	std::string numb[] = {
		"120",
		"-120",
		"33000",
		"-33000",
		"67000",
		"1h3"
	};

	for (int i = 0; i < sizeof(numb) / 40; i++)
	{
		try
		{
			MyFile::serialize(numb[i]);

			std::cout << "All correct" << std::endl;
		}
		catch (std::string ex)
		{
			std::cout<<"Error: " << ex << std::endl;
		}
	}
	return 0;
}
#include"stdafx.h"
#include"Generator.h"

int main()
{
	std::list<short> allShort = FileDiser::GetShort();
	std::list<unsigned short> allUshort = FileDiser::getUshort();

	std::cout << "All Short" << std::endl;
	for (const auto& elem : allShort)
		std::cout << elem << std::endl;

	std::cout << "All Unsigned Short" << std::endl;
	for (const auto& elem : allUshort)
		std::cout << elem << std::endl;

	Generator::getGenerator(allShort, allUshort);

	return 0;
}
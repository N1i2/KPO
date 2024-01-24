#pragma once

namespace FileDiser
{
	const char dataShort = '0x01';
	const char dataUshort = '0x02';

	const std::string path = "..\\..\\file.bin";

	std::list<short> GetShort();
	std::list<unsigned short> getUshort();
}
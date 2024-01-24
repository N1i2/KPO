#pragma once

namespace MyFile
{
	const char dataShort = '0x01';
	const char dataUshort = '0x02';
	const std::string path = "..\\..\\file.bin";

	void serialize(std::string& datas);

	void ClearFile();
}
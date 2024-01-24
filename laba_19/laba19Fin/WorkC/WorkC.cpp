#include<iostream>

extern "C"
{
	int __stdcall getmax(int*, int);
	int __stdcall getmin(int*, int);
}

void main()
{
	int h[10] = {11, 54, 7, 2, 7,81, -9, 6, -25, 4};
	int max, min, result;

	max = getmax(h, 10);
	min = getmin(h, 10);
	result = max + min;

	std::cout << result << std::endl;
}
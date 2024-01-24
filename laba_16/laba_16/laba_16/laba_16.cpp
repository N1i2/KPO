#include "stdafx.h"
#include "FST.h"

FST::FST cr(char str[]);
FST::FST creat(char str[]);
void show(FST::FST fst);

int _tmain(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	char str[] = "aaabbaba";

	FST::FST fst(str, 4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);

	show(fst);

	char str1[] = "fa)(b;(a));";//не будет читать все строчки
	char str2[] = "f(a)(b;(a))";//дочитает до конца но все равно забракует
	char str3[] = "f(a)(b;(a));";
	char str4[] = "f(a)(b;(a))s;";
	char str5[] = "f(a)(b;(a))sss;";
	char str6[] = "f(a)(b;(a))sss;";
	char str7[] = "f(a)(b;(a)(a))sss;";
	char str8[] = "f(a)(b;(a)(a));";
	char str9[] = "f(a)(b;(a)(a)(a)(a))ssssssss;";

	FST::FST fst1 = creat(str1);
	FST::FST fst2 = creat(str2);
	FST::FST fst3 = creat(str3);
	FST::FST fst4 = creat(str4);
	FST::FST fst5 = creat(str5);
	FST::FST fst6 = creat(str6);
	FST::FST fst7 = creat(str7);
	FST::FST fst8 = creat(str8);
	FST::FST fst9 = creat(str9);

	show(fst1);
	show(fst2);
	show(fst3);
	show(fst4);
	show(fst5);
	show(fst6);
	show(fst7);
	show(fst8);
	show(fst9);

	/*char word1[] = "All correct";
	char word2[] = "all Correct";
	char word3[] = "Al corect";
	char word4[] = "Allllll corrrrrrrect";
	char word5[] = "Allcorrect";

	FST::FST fst1 = cr(word1);
	FST::FST fst2 = cr(word2);
	FST::FST fst3 = cr(word3);
	FST::FST fst4 = cr(word4);
	FST::FST fst5 = cr(word5);

	show(fst1);
	show(fst2);
	show(fst3);
	show(fst4);
	show(fst5);*/

	system("pause");
	return 0;
}

void show(FST::FST fst)
{
	if (FST::execute(fst))
		std::cout << "Цепочка " << fst.string << " распознана" << std::endl;
	else std::cout << "Цепочка " << fst.string << " не распознана" << std::endl;
}

FST::FST cr(char str[])
{
	FST::FST fst(str, 10,
		FST::NODE(2, FST::RELATION('A', 1), FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('l', 1), FST::RELATION('l', 2)),
		FST::NODE(2, FST::RELATION(' ', 3), FST::RELATION(' ', 2)),
		FST::NODE(2, FST::RELATION('c', 4), FST::RELATION('C', 4)),
		FST::NODE(1, FST::RELATION('o', 5)),
		FST::NODE(2, FST::RELATION('r', 5), FST::RELATION('r', 6)),
		FST::NODE(1, FST::RELATION('e', 7)),
		FST::NODE(1, FST::RELATION('c', 8)),
		FST::NODE(1, FST::RELATION('t', 9)),
		FST::NODE()
	);

	return fst;
}

FST::FST creat(char str[])
{
	FST::FST fst(str, 14,
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('(', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE(1, FST::RELATION(')', 4)),
		FST::NODE(1, FST::RELATION('(', 5)),
		FST::NODE(1, FST::RELATION('b', 6)),
		FST::NODE(1, FST::RELATION(';', 7)),
		FST::NODE(1, FST::RELATION('(', 8)),
		FST::NODE(1, FST::RELATION('a', 9)),
		FST::NODE(2, FST::RELATION(')', 10), FST::RELATION(')', 7)),
		FST::NODE(2, FST::RELATION(')', 11), FST::RELATION(')', 12)),
		FST::NODE(2, FST::RELATION('s', 12), FST::RELATION('s', 11)),
		FST::NODE(1, FST::RELATION(';', 13)),
		FST::NODE()
	);

	return fst;
}
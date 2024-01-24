#pragma once
#include"stdafx.h"

namespace FST
{
	struct RELATION			//ребро: символ -> вершина графа переходов КА
	{
		char symbol;	//символ перехода
		short nnode;	//номер смежной вершин
		RELATION(
			char c = 0x00,	//символ перехода
			short ns = NULL	//новое состояние
		);
	};

	struct NODE		//вершина графа переходов
	{
		short n_relation;		//количество инциндентных ребер
		std::vector<RELATION> relations;	//инциндентные ребра
		NODE();
		NODE(
			short n,			//количество инциндентных ребер
			RELATION rel, ...	//список ребер
		);
	};

	struct FST			//недетерминированный конецчный автомат
	{
		char* string;	//цепочка (строка, завершаеться 0х00)
		short position;	//текущая позиция в цепочке
		short nstates;	//количество состояний автомата
		NODE* nodes;	//граф переходов: [0] -начальное сосотояние, [nstate-1] -конечное
		std::vector<short> rstates;	//воможные состояния автомата на данной позиции
		FST(
			char* s,	//цепочка (строка, завершаеться 0х00)
			short ns,	//количество состояний автомата
			NODE n, ...	//список состояний (граф переходов)
		);
	};

	bool execute(FST fst);
	bool step(FST& fst);
};
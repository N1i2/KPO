#include"FST.h"

namespace FST
{
	RELATION::RELATION(char c, short ns)
	{
		this->symbol = c;
		this->nnode = ns;
	}

	NODE::NODE()
	{
		this->n_relation = NULL;
	}

	NODE::NODE(short n, RELATION rel, ...)
	{
		this->n_relation = n;
		RELATION* wpned = &rel;

		for (int i = 0; i < n; i++)
			relations.push_back(wpned[i]);
	}

	FST::FST(char* s, short ns, NODE n, ...)
	{
		this->position = 0;
		this->string = s;
		this->nstates = ns;
		this->nodes = new NODE[ns];

		for (size_t i = 0; i < ns; i++)
		{
			this->rstates.push_back(0xff);
		}

		rstates[0] = 0;

		NODE* wned = &n;

		for (size_t i = 0; i < ns; i++)
		{
			nodes[i] = wned[i];
		}
	}

	bool execute(FST fst)
	{
		while (fst.position < strlen(fst.string))
		{
			if (step(fst))
				fst.position++;
			else
				return false;
		}

		return fst.rstates.back() == strlen(fst.string);
	}

	bool step(FST& fst)
	{
		std::vector<short> temp(fst.nstates);
		bool rc = false;

		for (size_t i = 0; i < fst.nstates; i++)
		{
			if (fst.rstates[i] != fst.position)
				continue;

			for (auto rel : fst.nodes[i].relations)
				if (fst.string[fst.position] == rel.symbol)
				{
					temp[rel.nnode] = fst.position + 1,
						rc = true;
				}
		}

		fst.rstates = std::move(temp);
		return rc;
	}
};
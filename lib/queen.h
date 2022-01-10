#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class queen : public piece{
	public:
		queen(char name, bool m, short int c, short int r);
		queen(char name, bool m, short int c, short int r, int m, int lm);
		~queen();

		queen(const queen& k);
		//queen& operator=(const queen& k);

		queen(queen&& k);
		//queen& operator=(queen&& k);

		bool is_valid_final_pos(short int c, short int r);
};
#endif

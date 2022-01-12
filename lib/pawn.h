#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class pawn : public piece{
	public:
		pawn(char name, short int c, short int r);
		pawn(char name, short int c, short int r, int m, int lm);
		//~pawn();

		//pawn(const pawn& k);
		//pawn& operator=(const pawn& k);

		//pawn(pawn&& k);
		//pawn& operator=(pawn&& k);

		bool is_valid_final_pos(short int c, short int r);
};

#endif

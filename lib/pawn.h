#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class pawn : public piece{
	public:
		pawn(char name, bool m, short int c, short int r);
		~pawn();

		pawn(const pawn& k);
		//pawn& operator=(const pawn& k);

		pawn(pawn&& k);
		//pawn& operator=(pawn&& k);

		bool is_valid_final_pos(short int c, short int r);
};

#endif

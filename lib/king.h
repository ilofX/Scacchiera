//
// Created by Nicolò Tesser on 22/12/2021
//

#ifndef KING_H
#define KING_H

#include "piece.h"

class king : public piece{
	public:
		king(char name, short int c, short int r);
		king(char name, short int c, short int r, int m, int lm);
		//~king();

		//king(const king& k);
		//king& operator=(const king& k);

		//king(king&& k);
		//king& operator=(king&& k);

		bool is_valid_final_pos(short int c, short int r);
};

#endif

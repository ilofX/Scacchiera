//
// Created by Nicolo' Tesser on 22/12/2021
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

        vector<short int> n_move();
        vector<short int> ne_move();
        vector<short int> e_move();
        vector<short int> se_move();
        vector<short int> s_move();
        vector<short int> sw_move();
        vector<short int> w_move();
        vector<short int> nw_move();
        vector<short int> castlingE_move();
        vector<short int> castlingW_move();


    bool is_valid_final_pos(short int c, short int r);
};

#endif

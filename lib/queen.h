//
// Created by Nicolo' Tesser on 22/12/2021
//
#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class queen : public piece{
	public:
		queen(char name, short int c, short int r);
		queen(char name, short int c, short int r, int m, int lm);
		//~queen();

		//queen(const queen& k);
		//queen& operator=(const queen& k);

		//queen(queen&& k);
		//queen& operator=(queen&& k);

        vector<short int> n_move();
        vector<short int> ne_move();
        vector<short int> e_move();
        vector<short int> se_move();
        vector<short int> s_move();
        vector<short int> sw_move();
        vector<short int> w_move();
        vector<short int> nw_move();

		bool is_valid_final_pos(short int c, short int r);
};
#endif

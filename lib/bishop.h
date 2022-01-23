//
// Created by Nicolo' Tesser on 22/12/2021
//
#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"


class bishop : public piece{
	public:
		bishop(char name, short int c, short int r);
		bishop(char name, short int c, short int r, int m, int lm);

        vector<short int> ne_move();
        vector<short int> nw_move();
        vector<short int> se_move();
        vector<short int> sw_move();

		bool is_valid_final_pos(short int c, short int r);
};
#endif

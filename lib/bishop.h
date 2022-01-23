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
		//~bishop();

		//bishop(const bishop& k);
		//bishop& operator=(const bishop& k);

		//bishop(bishop&& k);
		//bishop& operator=(bishop&& k);

        vector<short int> ne_move();
        vector<short int> nw_move();
        vector<short int> se_move();
        vector<short int> sw_move();


		bool is_valid_final_pos(short int c, short int r);
};
#endif

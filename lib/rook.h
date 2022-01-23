//
// Created by Nicolo' Tesser on 22/12/2021
//
#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class rook : public piece{
	public:
		rook(char name, short int c, short int r);
		rook(char name, short int c, short int r, int m, int lm);
		//~rook();

		//rook(const rook& k);
		//rook& operator=(const rook& k);

		//rook(rook&& k);
		//rook& operator=(rook&& k);

        vector<short int> n_move();
        vector<short int> e_move();
        vector<short int> s_move();
        vector<short int> w_move();


    bool is_valid_final_pos(short int c, short int r);
};
#endif

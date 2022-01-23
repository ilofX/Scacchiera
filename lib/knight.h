//
// Created by Nicolo' Tesser on 22/12/2021
//
#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class knight : public piece{
	public:
		knight(char name, short int c, short int r);
		knight(char name, short int c, short int r, int m, int lm);

        vector<short int> nne_move();
        vector<short int> nee_move();
        vector<short int> nnw_move();
        vector<short int> nww_move();
        vector<short int> see_move();
        vector<short int> sse_move();
        vector<short int> ssw_move();
        vector<short int> sww_move();

        bool is_valid_final_pos(short int c, short int r);
};
#endif

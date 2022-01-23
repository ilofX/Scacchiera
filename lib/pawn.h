//
// Created by Nicolo' Tesser on 22/12/2021
//
#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class pawn : public piece{
	public:
		pawn(char name, short int c, short int r);
		pawn(char name, short int c, short int r, int m, int lm);

        vector<short int> eatE_move();
        vector<short int> eatW_move();
        vector<short int> en_passantE_move();
        vector<short int> en_passantW_move();
        vector<short int> step_move();


		bool is_valid_final_pos(short int c, short int r);
};

#endif

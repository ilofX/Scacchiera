//
//Created by Nicolo' Tesser on 22/12/2021
//

#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class computer : public player{
	public:
		computer(char n, board& t);

		bool is_human();

		bool is_valid_input(short int c, short int r);

		shared_ptr<piece> get_random_piece(char c);
		char get_random_piece_to_promote(char c);
		short int get_random_col(shared_ptr<piece> p);
		short int get_random_row(shared_ptr<piece> p);

		bool move(string s);
};

#endif

//
// Created by Nicol� Tesser on 22/12/2021
//
#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class computer : public player{
	public:
		computer(char n, board& t);

		//computer(const computer& h);
		//computer(computer&& h);

		//computer& operator=(const computer& h);
		//computer& operator=(computer&& h);

		shared_ptr<piece> get_random_piece(char c);

		//bool is_ranndom_move_valid();

		short int get_random_col(shared_ptr<piece> p);
		short int get_random_row(shared_ptr<piece> p);

		string move_to_string(short int sc, short in sr, short int ec, short int er);

		bool move(string s);

		//~computer();
};

#endif

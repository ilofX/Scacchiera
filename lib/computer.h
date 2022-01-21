//
// Created by Nicolo Tesser on 22/12/2021
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

		bool is_human();

		shared_ptr<piece> get_random_piece(char c);

		char get_random_piece_to_promote();

		//bool is_ranndom_move_valid();

		short int get_random_col(shared_ptr<piece> p);
		short int get_random_row(shared_ptr<piece> p);

		bool move(string s);

		~computer() = default;
};

#endif

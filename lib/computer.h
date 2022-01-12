#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class computer : public player{
	public:
		computer(string n);

		//computer(const computer& h);
		//computer(computer&& h);

		//computer& operator=(const computer& h);
		//computer& operator=(computer&& h);

		piece get_random_piece();

		//bool is_ranndom_move_valid();

		short int get_random_col(const piece& p);
		short int get_random_row(const piece& p);

		bool move(string s);

		//~computer();
};

#endif

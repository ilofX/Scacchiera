//
//Created by Nicolo' Tesser on 22/10/2021
//

#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class human : public player{
	public:
		human(char n, board& t);

		bool is_valid_input(string s);
		bool is_display_input(string s);

		bool is_human();
		vector<short int> convert_input(string s);
		bool move(string s);
};

#endif


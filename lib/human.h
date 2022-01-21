//
// Created by Nicol� Tesser on 22/12/2021
//
#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class human : public player{
	public:
		human(char n, board& t);

		//human(const human& h);
		//human(human&& h);

		//human& operator=(const human& h);
		//human& operator=(human&& h);

		bool move(string s);
        bool is_human();
    protected:
        vector<short int> convert_input(string s);


		//~human();
};

#endif

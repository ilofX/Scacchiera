//
// Created by Nicolò Tesser on 22/12/2021
//
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <cstdlib>
#include "board.h"

using namespace std;

class player{
	public:
		player(char n, board& t);

		//player(const player& p);
		//player(player&& p);

		//player& operator=(const player& p);
		//player& operator=(player&& p);

		virtual bool move(string s); //è un vector di 4 elementi [start_col, start_row, end_col, end_row]

		bool is_valid_input(string s);

		bool is_display_input(string s);

		vector<short int> convert_input(string s);

		char get_color();

        class InvalidColorException : public std::exception{};
        class InvalidMoveException : public std::exception{};

		//virtual ~player();
	protected:
		char color;
		board& scacchiera;
};

#endif

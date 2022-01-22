//
//Created by Nicolo' Tesser on 22/12/2021
//

#ifndef PLAYER_H
#define PLAYER_H

#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include "board.h"

using namespace std;

class player{
	public:
		player(char n, board& t);

		char get_color();
		board get_board();

		bool is_valid_input(string s);
		bool is_display_input(string s);

		virtual bool move(string s);

		virtual bool is_human();

		class InvalidColorException : public std::exception{};
		class InvalidMoveException : public std::exception{};
		class InvalidInputException : public std::exception{};
		class InvalidStateException : public std::exception{};

	private:
		char color;
		board& scacchiera;
};

#endif


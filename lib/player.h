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

		virtual bool move(string s) = 0;

		virtual bool is_human() = 0;

		class InvalidColorException : public std::exception{};
		class InvalidMoveException : public std::exception{};
		class InvalidInputException : public std::exception{};
		class InvalidStateException : public std::exception{};

	protected:
		char color;
		board& scacchiera;
};

#endif


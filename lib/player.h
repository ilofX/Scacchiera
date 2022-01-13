#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <cstdlib>
#include "tabellone.h"

using namespace std;

class player{
	public:
		player(char n, const tabellone& t);

		//player(const player& p);
		//player(player&& p);

		//player& operator=(const player& p);
		//player& operator=(player&& p);

		virtual bool move(string s); //è un vector di 4 elementi [start_col, start_row, end_col, end_row]

		bool is_valid_input(string s);

		bool is_display_input(string s);

		vector<short int> convert_input(string s);

        class InvalidMoveException : public std::exception{};

		//virtual ~player();
	protected:
		char color;
		tabellone& scacchiera;
};

#endif

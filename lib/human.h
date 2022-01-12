#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class human : public player{
	public:
		human(char n, const tabellone& t);

		//human(const human& h);
		//human(human&& h);

		//human& operator=(const human& h);
		//human& operator=(human&& h);

		bool move(string s);

		//~human();
};

#endif

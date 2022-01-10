#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class human : public player{
	public:
		human(string n);

		//human(const human& h);
		//human(human&& h);

		//human& operator=(const human& h);
		//human& operator=(human&& h);

		bool move(short int sc, short int sr, short int ec, short int er);

		//~human();
};

#endif

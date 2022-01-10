#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class knight : public piece{
	public:
		knight(char name, bool m, short int c, short int r);
		knight(char name, bool m, short int c, short int r, int m, int lm);
		~knight();

		knight(const knight& k);
		//knight& operator=(const knight& k);

		knight(knight&& k);
		//knight& operator=(knight&& k);

		bool is_valid_final_pos(short int c, short int r);
};
#endif

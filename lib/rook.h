#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class rook : public piece{
	public:
		rook(char name, bool m, short int c, short int r);
		~rook();

		rook(const rook& k);
		//rook& operator=(const rook& k);

		rook(rook&& k);
		//rook& operator=(rook&& k);

		bool is_valid_final_pos(short int c, short int r);
};
#endif

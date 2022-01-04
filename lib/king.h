#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class king : public piece{
	public:
		king(char name, bool m, short int c, short int r);
		~king();

		king(const king& k);
		//king& operator=(const king& k);

		king(king&& k);
		//king& operator=(king&& k);

		bool is_valid_final_pos(short int c, short int r);
};
#endif

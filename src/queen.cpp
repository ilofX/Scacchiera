#include "queen.h"

queen::queen(char name, short int c, short int r) : piece(name, r, c){}

queen::queen(char name, short int c, short int r, int m, int lm) : piece(name, r, c, m, lm){}

queen::queen(const queen& k) : piece(k){}

queen::queen(queen&& k) : piece(k){}

//queen& queen::operator=(const queen& k) : piece(k){}

//queen& queen::operator=(queen&& k) : piece(k){}

bool queen::is_valid_final_pos(short int c, short int r){
	if((c-(this->get_column()) == 0 && (r >= 0 && r <= 7)) || (r-(this->get_row()) == 0 && (c >= 0 && c <= 7)) || (abs(c-(this->get_column())) == abs(r-(this->get_row())))){
		return true;
	}else{
		return false;
	}
}

#include "rook.h"

rook::rook(char name, short int c, short int r) : piece(name, r, c){}

rook::rook(char name, short int c, short int r, int m, int lm) : piece(name, r, c, m, lm){}

//rook::rook(const rook& k) : piece(k){}

//rook::rook(rook&& k) : piece(k){}

//rook& rook::operator=(const rook& k) : piece(k){}

//rook& rook::operator=(rook&& k) : piece(k){}

bool rook::is_valid_final_pos(short int c, short int r){
	if((c-(this->get_column()) == 0 && (r >= 0 && r <= 7)) || (r-(this->get_row()) == 0 && (c >= 0 && c <= 7))){
		return true;
	}else{
		return false;
	}
}

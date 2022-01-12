#include "bishop.h"

bishop::bishop(char name, short int c, short int r) : piece(name, r, c){}

bishop::bishop(char name, short int c, short int r, int m, int lm) : piece(name, r, c, m, lm){}

//bishop::bishop(const bishop& k) : piece(k){}

//bishop::bishop(bishop&& k) : piece(k){}

//bishop& bishop::operator=(const bishop& k) : piece(k){}

//bishop& bishop::operator=(bishop&& k) : piece(k){}

bool bishop::is_valid_final_pos(short int c, short int r){
	if((abs(c-(this->get_column()))==(abs(r-(this->get_row()))))){
		return true;
	}else{
		return false;
	}
}

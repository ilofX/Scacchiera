#include "queen.h"

queen::queen(char name, short int c, short int r) : piece(name, r, c){}

queen::queen(const queen& k) : piece(k){}

queen::queen(queen&& k) : piece(k){}

queen& queen::operator=(const queen& k) : piece(k){}

queen& queen::operator=(queen&& k) : piece(k){}

bool queen::is_valid_final_pos(short int c, short int r){
	if((c-column == 0 && (r >= 0 && r <= 7)) || (r-row == 0 && (c >= 0 && c <= 7)) || (abs(c-column) == abs(r-row))){
		return true;
	}else{
		return false;
	}
}

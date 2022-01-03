#include "king.h"

king::king(char name, short int c, short int r) : piece(name, r, c){}

king::king(const king& k) : piece(k){}

king::king(king&& k) : piece(k){}

king& king::operator=(const king& k) : piece(k){}

king& king::operator=(king&& k) : piece(k){}

bool king::is_valid_final_pos(short int c, short int r){
	if((c-column == 0 && abs(r-row) == 1) && (r-row == 0 && abs(c-column) == 1) || (abs(c-column) == 1 && abs(r-row) == 1) || (!(this->is_moved()) && r-row == 0 && abs(c-column) == 2)){
			return true;
	}else{
		return false;
	}
}

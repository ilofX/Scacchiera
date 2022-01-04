#include "knight.h"

knight::knight(char name, bool m, short int c, short int r) : piece(name, m, r, c){}

knight::knight(const knight& k) : piece(k){}

knight::knight(knight&& k) : piece(k){}

//knight& knight::operator=(const knight& k) : piece(k){}

//knight& knight::operator=(knight&& k) : piece(k){}

bool knight::is_valid_final_pos(short int c, short int r){
	if((abs(r-(this->get_row()))==1 && abs(c-(this->get_column()))==2) || (abs(r-(this->get_row()))==2 && abs(c-(this->get_column()))==1)){
		return true;
	}else{
		return false;
	}
}

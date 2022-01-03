#include "knight.h"

knight::knight(char name, short int c, short int r) : piece(name, r, c){}

knight::knight(const knight& k) : piece(k){}

knight::knight(knight&& k) : piece(k){}

knight& knight::operator=(const knight& k) : piece(k){}

knight& knight::operator=(knight&& k) : piece(k){}

bool knight::is_valid_final_pos(short int c, short int r){
	if((abs(r-row)==1 && abs(c-column)==2) || (abs(r-row)==2 && abs(c-column)==1)){
		return true;
	}else{
		return false;
	}
}

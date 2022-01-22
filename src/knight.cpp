//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "knight.h"

knight::knight(char name, short int c, short int r) : piece(name, c, r){}

knight::knight(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

//knight::knight(const knight& k) : piece(k){}

//knight::knight(knight&& k) : piece(k){}

//knight& knight::operator=(const knight& k) : piece(k){}

//knight& knight::operator=(knight&& k) : piece(k){}

bool knight::is_valid_final_pos(short int c, short int r){
	if((abs(r-(this->get_row()))==1 && abs(c-(this->get_column()))==2) || (abs(r-(this->get_row()))==2 && abs(c-(this->get_column()))==1)){
		return true;
	}else{
		return false;
	}
}

//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "bishop.h"

bishop::bishop(char name, short int c, short int r) : piece(name, c, r){}

bishop::bishop(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

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

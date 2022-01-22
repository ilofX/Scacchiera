//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "king.h"

king::king(char name, short int c, short int r) : piece(name, c, r){}

king::king(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

//king::king(const king& k) : piece(k){}

//king::king(king&& k) : piece(k){}

//king& king::operator=(const king& k) : piece(k){}

//king& king::operator=(king&& k) : piece(k){}

bool king::is_valid_final_pos(short int c, short int r){
	if((c-(this->get_column()) == 0 && abs(r-(this->get_row())) == 1) || (r-(this->get_row()) == 0 && abs(c-(this->get_column())) == 1) || (abs(c-(this->get_column())) == 1 && abs(r-this->get_row()) == 1) || (!(this->is_moved()) && r-(this->get_row()) == 0 && abs(c-(this->get_column())) == 2)){
			return true;
	}else{
		return false;
	}
}

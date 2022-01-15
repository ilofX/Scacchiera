//
// Created by Nicolò Tesser on 22/12/2021
//
#include "pawn.h"

pawn::pawn(char name, short int c, short int r) : piece(name, r, c){}

pawn::pawn(char name, short int c, short int r, int m, int lm) : piece(name, r, c, m, lm){}

//pawn::pawn(const pawn& k) : piece(k){}

//pawn::pawn(pawn&& k) : piece(k){}

//pawn& pawn::operator=(const pawn& k) : piece(k){}

//pawn& pawn::operator=(pawn&& k) : piece(k){}

bool pawn::is_valid_final_pos(short int c, short int r){
	if(this->get_piece_name() <= 104 && this->get_piece_name() >= 97){ //pezzo bianco
		if((c-(this->get_column()) == 0 && r-(this->get_row()) == -1) || (abs(c-(this->get_column())) == 1 && r-(this->get_row()) == -1) || (!(this->is_moved()) && c-(this->get_column()) == 0 && r-(this->get_row()) == -2)){
			return true;
		}
	}else if(this->get_piece_name() <= 72 && this->get_piece_name() >= 65){ //pezzo nero
		if((c-(this->get_column()) == 0 && r-(this->get_row()) == 1) || (abs(c-(this->get_column())) == 1 && r-(this->get_row()) == 1) || (!(this->is_moved()) && c-(this->get_column()) == 0 && r-(this->get_row()) == 2)){
			return true;
		}
	}
    return false;
}


#include "pawn.h"

pawn::pawn(char name, short int c, short int r) : piece(name, r, c){}

pawn::pawn(const pawn& k) : piece(k){}

pawn::pawn(pawn&& k) : piece(k){}

pawn& pawn::operator=(const pawn& k) : piece(k){}

pawn& pawn::operator=(pawn&& k) : piece(k){}

bool pawn::is_valid_final_pos(short int c, short int r){
	if(this->get_piece_name() <= 104 && this->get_piece_name() >= 97){ //pezzo bianco
		if((c-column == 0 && r-row == -1) || (abs(c-column) == 1 && r-row == -1) || (!(this->is_moved()) && c-colum == 0 && r-row == -2)){
			return true;
		}else{
			return false;
		}
	}else if(this->piece_name <= 72 && this->piece_name >= 65){ //pezzo nero
		if((c-column == 0 && r-row == 1) || (abs(c-column) == 1 && r-row == 1) || (!(this->is_moved()) && c-colum == 0 && r-row == 2)){
			return true;
		}else{
			return false;
		}
	}
}
		

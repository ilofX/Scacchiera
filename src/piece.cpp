#include "piece.h"

piece::piece(char name, bool m, short int c, short int r) :piece_name{name}, moved{m}, column{c}, row{r}{}

piece::piece(const piece& p) :piece_name{p.piece_name}, moved{p.moved}, column{p.column}, row{p.row}{}

piece::piece(piece&& p) :piece_name{p.piece_name}, moved{p.moved}, column{p.column}, row{p.row}{
	p.piece_name = " ";
	p.moved = false;
	p.column = 0;
	p.row = 0;
}

piece& piece::operator=(const piece& p) :piece_name{p.piece_name}, moved{p.moved}, column{p.column}, row{p.row}{
	return *this;
}


piece& piece::operator=(piece&& p) :piece_name{p.piece_name}, moved{p.moved}, column{p.column}, row{p.row}{
	p.piece_name = " ";
	p.moved = false;
	p.column = 0;
	p.row = 0;

	return *this;
}

short int[] piece::get_position(){
	short int r[2];
	r[0] = column;
	r[1] = row;
	return r;
}

void piece::set_position(short int r, short int c){
	if(r < 0 || r >= 8 || c < 0 || c >= 8){
		throw invalid_argument("Riga o colonna non valida!");
	}else{
		column = c;
		row = r;
	}
}

bool piece::is_moved(){
	return moved;
}

void piece::set_moved(bool m){
	if(m == true){
		moved = m;
	}
}

char piece::get_piece_name(){
	return piece_name;
}

void piece::set_piece_name(char n){
	if((n <= 104 && n >= 97) || (n <= 72 && n >= 65)){
		piece_name = n;
	}else{
		piece_name = " ";
	}	
}

string piece::to_string(){
	return (string)this->piece_name;
}

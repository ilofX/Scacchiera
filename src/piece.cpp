#include "piece.h"

piece::piece(char name, char r, char c) :piece_name{name}, row{r}, column{c}{}

piece::piece(const piece& p) :piece_name{p.piece_name}, row{p.row},column{p.column}{}

piece::piece(piece&& p) :piece_name{p.piece_name}, row{p.row}, column{p.column}{
	p.piece_name = " ";
	p.column = 0;
	p.row = 0;
}

piece& piece::operator=(const piece& p) :piece_name{p.piece_name}, row{p.row}, column{p.column}{
	return *this;
}


piece& piece::operator=(piece&& p) :piece_name{p.piece_name}, row{p.row}, column{p.column}{
	p.piece_name = " ";
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
	if(r <= 0 || r >= 8 || c <= 0 || c >= 8){
		throw invalid_argument("Riga o colonna non valida!");
	}else{
		row = r;
		column = c;
	}
}

string piece::to_string(){
	return (string)this->piece_name;
}

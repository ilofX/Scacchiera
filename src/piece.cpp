//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "piece.h"

using namespace std;

piece::piece(char name, short int c, short int r) :piece_name{name}, moves{0}, last_moved{0}, column{c}, row{r}{}

piece::piece(char name, short int c, short int r, int moves, int last_moved) :piece_name{name}, moves{moves}, last_moved{last_moved}, column{c}, row{r}{}

/*piece::piece(const piece& p) :piece_name{p.piece_name}, moves{p.moves}, last_moved{p.last_moved}, column{p.column}, row{p.row}{}

piece::piece(piece&& p) :piece_name{p.piece_name}, moves{p.moves}, last_moved{p.last_moved}, column{p.column}, row{p.row}{
	p.piece_name = ' ';
	p.moves = 0;
    p.last_moved = 0;
	p.column = 0;
	p.row = 0;
}

piece& piece::operator=(const piece& p){
	piece_name = p.piece_name;
	moves = p.moves;
    last_moved = p.last_moved;
	column = p.column;
	row = p.row;
	return *this;
}

piece& piece::operator=(piece&& p){
	piece_name = p.piece_name;
	moves = p.moves;
    last_moved = p.last_moved;
	column = p.column;
	row = p.row;

	p.piece_name = ' ';
	p.moves = 0;
    p.last_moved = 0;
	p.column = 0;
	p.row = 0;

	return *this;
}

*/

short int piece::get_column() const{
	return column;
}

short int piece::get_row() const{
	return row;
}

void piece::set_position(short int c, short int r){
	if(r < 0 || r >= 8 || c < 0 || c >= 8){
		throw invalid_argument("Riga o colonna non valida!");
	}else{
		column = c;
		row = r;
	}
}

bool piece::is_moved() const{
	return moves>0;
}

void piece::increment_move(int turn){
    moves++;
    last_moved = turn;
}

char piece::get_piece_name() const{
	return piece_name;
}

void piece::set_piece_name(char n){
	if((n <= 104 && n >= 97) || (n <= 72 && n >= 65)){
		piece_name = n;
	}else{
		piece_name = ' ';
	}
}

int piece::get_moves() const {
    return moves;
}

int piece::get_last_moved() const {
    return last_moved;
}

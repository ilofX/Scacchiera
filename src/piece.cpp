//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "piece.h"

using namespace std;

piece::piece(char name, short int c, short int r) :piece_name{name}, moves{0}, last_moved{0}, column{c}, row{r}{}

piece::piece(char name, short int c, short int r, int moves, int last_moved) :piece_name{name}, moves{moves}, last_moved{last_moved}, column{c}, row{r}{}

/// <summary>
/// used to return the piece's column
/// </summary>
short int piece::get_column() const{
	return column;
}

/// <summary>
/// used to return the piece's row
/// </summary>
short int piece::get_row() const{
	return row;
}

/// <summary>
/// used to set the piece's column and row
/// </summary>
void piece::set_position(short int c, short int r){
	if(r < 0 || r >= 8 || c < 0 || c >= 8){
		throw invalid_argument("Riga o colonna non valida!");
	}else{
		column = c;
		row = r;
	}
}

/// <summary>
/// used to return if the piece was moved before
/// </summary>
bool piece::is_moved() const{
	return moves>0;
}

/// <summary>
/// used to count the piece's moves
/// </summary>
void piece::increment_move(int turn){
    moves++;
    last_moved = turn;
}

/// <summary>
/// used to return the piece's name
/// </summary>
char piece::get_piece_name() const{
	return piece_name;
}

/// <summary>
/// used to set the piece's name
/// </summary>
void piece::set_piece_name(char n){
	if((n <= 104 && n >= 97) || (n <= 72 && n >= 65)){
		piece_name = n;
	}else{
		piece_name = ' ';
	}
}

/// <summary>
/// used to return the piece's move
/// </summary>
int piece::get_moves() const {
    return moves;
}

/// <summary>
/// used to return the last turn when the piece was moved
/// </summary>
int piece::get_last_moved() const {
    return last_moved;
}

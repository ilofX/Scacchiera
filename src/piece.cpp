#include "piece.h"

piece::piece(char col, char r, char c){
	color = col;
	row = r;
	column = c;
}

char piece::get_row(){
	return row;
}

char piece::get_column(){
	return column;
}

char piece::set_row(short int r){
	row = r;
}

char piece::set_column(short int c){
	column = c;
}

bool piece::is_same_color(const piece& p){
	return ((this->color)==(p.color));
}

piece::~piece(){

}

bool piece::is_valid_move(short int r, short int c){



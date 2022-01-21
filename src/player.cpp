//
// Created by Nicol� Tesser on 22/12/2021
//
#include "player.h"

player::player(char n, board& t): scacchiera{t} {
	if(n == 'b' || n == 'w' || n == 'B' || n == 'W'){
		color = n;
	}else{
		throw InvalidColorException();
	}
}

/*
player::player(const player& p) : color{p.color}, scacchiera{p.scacchiera} {}

player::player(player&& p) : color{p.color}, scacchiera{p.scacchiera} {
	p.color = ' ';
}

player& player::operator=(const player& p) {
	color = p.color;
	return *this;
}

player& player::operator=(player&& p) {
	color = p.color;
	p.color = ' ';
	return *this;
}
*/

bool player::is_valid_input(string s){
	if(s.length() == 5 && s[2] != ' ' && tolower((int)s[0]) >= 65 && tolower((int)s[0]) <= 72 && s[1] >= 49 && s[1] <= 56 && tolower((int)s[3]) >= 65 && tolower((int)s[3]) <= 72 && s[4] >= 49 && s[4] <= 56){
		return true;
	}else{
		return false;
	}
}

bool player::is_display_input(string s){
	string s1 = "XX XX";
	string s2 = "xx xx";
	if(s.compare(s1) == 0 || s.compare(s2) == 0){
		return true;
	}else{
		return false;
	}
}



char player::get_color(){
    return this->color;
}




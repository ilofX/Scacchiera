//
//Created by Nicolo' Tesser on 22/12/2021
//

#include <iostream>
#include "player.h"

player::player(char n, board& t) : color{n},scacchiera{t} {
	if(n == 'b' || n == 'w' || n == 'B' || n == 'W'){
		color = n;
	}else{
		throw InvalidColorException();
	}
}

char player::get_color(){
	return color;
}


bool player::is_valid_input(string s){
	if(s.length() == 5 && s[2] == ' ' && tolower((int)s[0]) >= 97 && tolower((int)s[0]) <= 104 && s[1] >= 49 && s[1] <= 56 && tolower((int)s[3]) >= 96 && tolower((int)s[3]) <= 104 && s[4] >= 49 && s[4] <= 56){
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

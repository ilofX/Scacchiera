//
//Created by Nicolo' Tesser on 22/12/2021
//
#include <iostream>
#include "human.h"
#include "piece.h"

human::human(char n, board& t) : player(n, t){}

bool human::move(string s){
    if(is_display_input(s)){
        std::cout << scacchiera.print() << std::endl;
        return false;
    }else if(!is_valid_input(s)){
		throw InvalidInputException();
	}else{
		vector<short int> v = convert_input(s);
		scacchiera.move(v[0], v[1], v[2], v[3]);
		return true;
	}
}

vector<short int> human::convert_input(string s){
	vector<short int> ret;

	if(is_valid_input(s) && !is_display_input(s)){
		ret.push_back((short int)(tolower((int)s[0]) - 97));
		ret.push_back((short int)(s[1] - 49));
		ret.push_back((short int)(tolower((int)s[3]) - 97));
		ret.push_back((short int)(s[4] - 49));
	}
	return ret;
}

bool human::is_human(){
	return true;
}

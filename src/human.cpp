//
//Created by Nicolo' Tesser on 22/12/2021
//
#include <iostream>
#include "human.h"
#include "piece.h"

human::human(char n, board& t) : player(n, t){}

/// <summary>
/// used to make the human's move
/// </summary>
std::string human::move(string s, bool isCheck){
    if(is_display_input(s)){
        std::cout << scacchiera.print() << std::endl;
        return s;
    }else if(!is_valid_input(s)){
		throw InvalidInputException();
	}else{
		vector<short int> v = convert_input(s);
        if(isCheck){
            if(!scacchiera.solvesCheck(v[0], v[1], v[2], v[3])){
                throw InvalidInputException();
            }
        }
		scacchiera.move(v[0], v[1], v[2], v[3]);
		return s;
	}
}

/// <summary>
/// used to convert the string input into 4 short int value
/// </summary>
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

/// <summary>
/// used to check the input validity
/// </summary>
bool human::is_valid_input(string s){
	if(s.length() == 5 && s[2] == ' ' && tolower((int)s[0]) >= 97 && tolower((int)s[0]) <= 104 && s[1] >= 49 && s[1] <= 56 && tolower((int)s[3]) >= 96 && tolower((int)s[3]) <= 104 && s[4] >= 49 && s[4] <= 56){
		return true;
	}else{
		return false;
	}
}

/// <summary>
/// used to check if the input string is 'xx xx' or 'XX XX' displays input strings
/// </summary>
bool human::is_display_input(string s){
	string s1 = "XX XX";
	string s2 = "xx xx";
	if(s.compare(s1) == 0 || s.compare(s2) == 0){
		return true;
	}else{
		return false;
	}
}

/// <summary>
/// used to know if the player is human or computer
/// </summary>
bool human::is_human(){
	return true;
}

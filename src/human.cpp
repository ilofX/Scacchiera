//
// Created by Nicol� Tesser on 22/12/2021
//
#include "human.h"
#include "piece.h"

human::human(char n, board& t) : player(n, t) {}

bool human::move(string s){
    if(!is_valid_input(s)){
        throw player::InvalidInputException();
    }else if(is_display_input(s)){
            this->scacchiera.print();
            return false;
            //break;
    }else{
        vector<short int> v = convert_input(s);
        this->scacchiera.move(v[0], v[1], v[2], v[3]);
        return true;
    }
}

vector<short int> human::convert_input(string s){ //il vettore tornato contiene [stat_col, start_row, end_col, end_row]
	vector<short int> ret;

	if(is_valid_input(s) && !is_display_input(s)){
		ret.push_back((short int)tolower((int)s[0]) - 96);
		ret.push_back((short int)s[1] - 48);
		ret.push_back((short int)tolower((int)s[2]) - 96);
		ret.push_back((short int)s[3] - 48);
    }

	return ret;
}

bool human::is_human(){
    return true;
}

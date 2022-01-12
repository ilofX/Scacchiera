#include "player.h"

player::player(char n, tabellone& t){
	scacchiera = t;
	if(n == 'b' || n == 'w' || n == 'B' || n == 'W'){
		color = n;
	}else{
		throw std::invalid_argument("Sono validi solo i colori b, w o B, W");
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

bool is_display_input(string s){
	string s1 = "XX XX";
	string s2 = "xx xx";
	if(s.compare(s1) == 0 || s.compare(s2) == 0){
		return true;
	}else{
		return false;
	}
}

vector<short int> player::convert_input(string s){ //il vettore tornato contiene [stat_col, start_row, end_col, end_row]
	vector<short int> ret;

	if(is_valid_input(s) && !is_display_input(s)){
		ret.push_back((short int)tolower((int)s[0]) - 64);
		ret.push_back((short int)s[1] - 48);
		ret.push_back((short int)tolower((int)s[2]) - 64);
		ret.push_back((short int)s[3] - 48);
    }

	return ret;
}




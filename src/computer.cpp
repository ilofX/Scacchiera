//
//Created by Nicolo' Tesser on 22/12/2021
//

#include "computer.h"
#include "player.h"

computer::computer(char n, board& t) : player(n, t){}

shared_ptr<piece> computer::get_random_piece(char c){
	srand(time(0));
	if(c == 'b' || c == 'B' || c == 'w' || c == 'W'){
		vector<shared_ptr<piece>> v = scacchiera.getPieces(c);
		int r = std::rand()%(v.size());
		return v[r];
	}else{
		throw player::InvalidStateException();
	}
}

char computer::get_random_piece_to_promote(char c){
	srand(time(0));
	char ret;
	int r = rand()%4;
	switch(r){
		case 1:
			if(c == 'b' || c == 'B'){
				ret = 'c';
			}else{
				ret = 'C';
			}
		case 2:
			if(c == 'b' || c == 'B'){
				ret = 't';
			}else{
				ret = 'T';
			}
		case 3:
			if(c == 'b' || c == 'B'){
				ret = 'a';
			}else{
				ret = 'A';
			}
		case 4:
			if(c == 'b' || c == 'B'){
				ret = 'd';
			}else{
				ret = 'D';
			}
	}
	return ret;
}

bool computer::is_human(){
	return false;
}

short int computer::get_random_col(shared_ptr<piece> p){
	srand(time(0));
	short int res, r;
	switch(p->get_piece_name()){
		case 'R':
		case 'r':
		case 'P':
		case 'p':
			r = -1 + std::rand()%3;
		
		case 'D':
		case 'd':
		case 'T':
		case 't':
		case 'A':
		case 'a':
			r = -7 + rand()%15;

		case 'C':
		case 'c':
			r = -2 + rand()%5;
	}
	res = r + p->get_column();
	return res;
}

short int computer::get_random_row(shared_ptr<piece> p){
	srand(time(0));
	short int res, r;
	switch(p->get_piece_name()){
		case 'R':
		case 'r':
			r = -1 + std::rand()%3;
		
		case 'D':
		case 'd':
		case 'T':
		case 't':
		case 'A':
		case 'a':
			r = -7 + rand()%15;

		case 'C':
		case 'c':
			r = -2 + rand()%5;
		case 'P':
			r = 0 + rand()%2;
		case 'p':
			r = -1 + rand()%2;
	}
	res = r + p->get_row();
	return res;
}

bool computer::move(string s){
	shared_ptr<piece> p = get_random_piece(this->get_color());
	short int ec = get_random_col(p);
	short int er = get_random_row(p);
	scacchiera.move(p->get_column(), p->get_row(), ec, er);
	return true;
}

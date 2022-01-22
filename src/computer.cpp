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

bool computer::is_valid_input(short int c, short int r){
    if(c > 7 || r > 7 || c < 0 || r < 0){
        return false;
    }else{
        return true;
    }
}

short int computer::get_random_col(shared_ptr<piece> p){
	//srand(time(0));
	short int res, r;
	switch(p->get_piece_name()){
		case 'R':
		case 'r':
            r = -2 + std::rand()%5;
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
    short int ec;
    short int er;

	while(!is_valid_input(get_random_col(p), get_random_row(p))){
            ec = get_random_col(p);
            er = get_random_row(p);
	}

    int trials = 0;
    bool done = false;

    while(!done && trials <= 100 && is_valid_input(ec, er)) {
        try {
            done = scacchiera.move(p->get_column(), p->get_row(), ec, er);
        }
        catch (board::IllegalMoveException &ex) { done = false; }
        catch (board::IllegalCoordinatesException &ex) { done = false; }
        trials++;
    }
    if(!done || trials > 100) throw player::InvalidMoveException();

	return true;
}

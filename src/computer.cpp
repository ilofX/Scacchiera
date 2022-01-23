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
/*
bool computer::move(string s){
	shared_ptr<piece> p = get_random_piece(this->get_color());
    short int ec;
    short int er;

	while(!is_valid_input(ec, er)){
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
*/

bool computer::move(string s) {
    vector<short int> v{0, 0};
    short int r;
    while (!is_valid_input(v[0], v[1])) {
        shared_ptr<piece> p = get_random_piece(this->get_color());
        switch (p->get_piece_name()) {
            case 'R':
            case 'r':
                r = std::rand() % 10;
                switch (r) {
                    case 1:
                        v = p->n_move();
                    case 2:
                        v = p->ne_move();
                    case 3:
                        v = p->e_move();
                    case 4:
                        v = p->se_move();
                    case 5:
                        v = p->s_move();
                    case 6:
                        v = p->sw_move();
                    case 7:
                        v = p->w_move();
                    case 8:
                        v = p->nw_move();
                    case 9:
                        v = p->castlingE_move();
                    case 10:
                        v = p->castlingW_move();
                }

            case 'D':
            case 'd':
                r = std::rand() % 8;
                switch (r) {
                    case 1:
                        v = p->n_move();
                    case 2:
                        v = p->ne_move();
                    case 3:
                        v = p->e_move();
                    case 4:
                        v = p->se_move();
                    case 5:
                        v = p->s_move();
                    case 6:
                        v = p->sw_move();
                    case 7:
                        v = p->w_move();
                    case 8:
                        v = p->nw_move();
                }
            case 'T':
            case 't':
                r = std::rand() % 4;
                switch (r) {
                    case 1:
                        v = p->n_move();
                    case 2:
                        v = p->e_move();
                    case 3:
                        v = p->s_move();
                    case 4:
                        v = p->w_move();
                }
            case 'A':
            case 'a':
                r = std::rand() % 4;
                switch (r) {
                    case 1:
                        v = p->ne_move();
                    case 2:
                        v = p->nw_move();
                    case 3:
                        v = p->se_move();
                    case 4:
                        v = p->sw_move();
                }
            case 'C':
            case 'c':
                r = std::rand() % 8;
                switch (r) {
                    case 1:
                        v = p->nne_move();
                    case 2:
                        v = p->nee_move();
                    case 3:
                        v = p->see_move();
                    case 4:
                        v = p->sse_move();
                    case 5:
                        v = p->ssw_move();
                    case 6:
                        v = p->sww_move();
                    case 7:
                        v = p->nww_move();
                    case 8:
                        v = p->nnw_move();
                }

            case 'P':
            case 'p':
                r = std::rand() % 5;
                switch (r) {
                    case 1:
                        v = p->eatE_move();
                    case 2:
                        v = p->eatW_move();
                    case 3:
                        v = p->en_passantE_move();
                    case 4:
                        v = p->en_passantW_move();
                    case 5:
                        v = p->step_move();
                }
        }
    }
}
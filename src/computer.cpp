//
//Created by Nicolo' Tesser on 22/12/2021
//

#include "computer.h"
#include "player.h"
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"


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

std::string computer::move(string s, bool isCheck) {
    bool done = false;
    int trials = 0;
    vector<short int> v{-1, -1};
    short int r;
    shared_ptr<piece> p = get_random_piece(this->get_color());
    while (!done && trials <= 50) {
        switch (p->get_piece_name()) {
            case 'R':
            case 'r':
                r = std::rand() % 10;
                switch (r) {
                    case 1:
                        v = (dynamic_cast<king&>(*p)).n_move();
                        break;
                    case 2:
                        v = (dynamic_cast<king&>(*p)).ne_move();
                        break;
                    case 3:
                        v = (dynamic_cast<king&>(*p)).e_move();
                        break;
                    case 4:
                        v = (dynamic_cast<king&>(*p)).se_move();
                        break;
                    case 5:
                        v = (dynamic_cast<king&>(*p)).s_move();
                        break;
                    case 6:
                        v = (dynamic_cast<king&>(*p)).sw_move();
                        break;
                    case 7:
                        v = (dynamic_cast<king&>(*p)).w_move();
                        break;
                    case 8:
                        v = (dynamic_cast<king&>(*p)).nw_move();
                        break;
                    case 9:
                        v = (dynamic_cast<king&>(*p)).castlingE_move();
                        break;
                    case 10:
                        v = (dynamic_cast<king&>(*p)).castlingW_move();
                        break;
                }
                break;

            case 'D':
            case 'd':
                r = std::rand() % 8;
                switch (r) {
                    case 1:
                        v = (dynamic_cast<queen&>(*p)).n_move();
                        break;
                    case 2:
                        v = (dynamic_cast<queen&>(*p)).ne_move();
                        break;
                    case 3:
                        v = (dynamic_cast<queen&>(*p)).e_move();
                        break;
                    case 4:
                        v = (dynamic_cast<queen&>(*p)).se_move();
                        break;
                    case 5:
                        v = (dynamic_cast<queen&>(*p)).s_move();
                        break;
                    case 6:
                        v = (dynamic_cast<queen&>(*p)).sw_move();
                        break;
                    case 7:
                        v = (dynamic_cast<queen&>(*p)).w_move();
                        break;
                    case 8:
                        v = (dynamic_cast<queen&>(*p)).nw_move();
                        break;
                }
                break;
            case 'T':
            case 't':
                r = std::rand() % 4;
                switch (r) {
                    case 1:
                        v = (dynamic_cast<rook&>(*p)).n_move();
                        break;
                    case 2:
                        v = (dynamic_cast<rook&>(*p)).e_move();
                        break;
                    case 3:
                        v = (dynamic_cast<rook&>(*p)).s_move();
                        break;
                    case 4:
                        v = (dynamic_cast<rook&>(*p)).w_move();
                        break;
                }
                break;
            case 'A':
            case 'a':
                r = std::rand() % 4;
                switch (r) {
                    case 1:
                        v = (dynamic_cast<bishop&>(*p)).ne_move();
                        break;
                    case 2:
                        v = (dynamic_cast<bishop&>(*p)).nw_move();
                        break;
                    case 3:
                        v = (dynamic_cast<bishop&>(*p)).se_move();
                        break;
                    case 4:
                        v = (dynamic_cast<bishop&>(*p)).sw_move();
                        break;
                }
                break;
            case 'C':
            case 'c':
                r = std::rand() % 8;
                switch (r) {
                    case 1:
                        v = (dynamic_cast<knight&>(*p)).nne_move();
                        break;
                    case 2:
                        v = (dynamic_cast<knight&>(*p)).nee_move();
                        break;
                    case 3:
                        v = (dynamic_cast<knight&>(*p)).see_move();
                        break;
                    case 4:
                        v = (dynamic_cast<knight&>(*p)).sse_move();
                        break;
                    case 5:
                        v = (dynamic_cast<knight&>(*p)).ssw_move();
                        break;
                    case 6:
                        v = (dynamic_cast<knight&>(*p)).sww_move();
                        break;
                    case 7:
                        v = (dynamic_cast<knight&>(*p)).nww_move();
                        break;
                    case 8:
                        v = (dynamic_cast<knight&>(*p)).nnw_move();
                        break;
                }
                break;

            case 'P':
            case 'p':
                r = std::rand() % 5;
                switch (r) {
                    case 1:
                        v = (dynamic_cast<pawn&>(*p)).eatE_move();
                        break;
                    case 2:
                        v = (dynamic_cast<pawn&>(*p)).eatW_move();
                        break;
                    case 3:
                        v = (dynamic_cast<pawn&>(*p)).en_passantE_move();
                        break;
                    case 4:
                        v = (dynamic_cast<pawn&>(*p)).en_passantW_move();
                        break;
                    case 5:
                        v = (dynamic_cast<pawn&>(*p)).step_move();
                        break;

                }
                break;
        }
        if(isCheck){
            if(!scacchiera.solvesCheck(p->get_column(), p->get_row(), v[0], v[1])){
                trials++;
                continue;
            }
        }
        try{
            done = this->scacchiera.move(p->get_column(), p->get_row(), v[0], v[1]);
        }
        catch (board::IllegalMoveException &ex) { done = false; }
        catch (board::IllegalCoordinatesException &ex) { done = false; }
        trials++;
    }
    if(!done || trials > 50) throw player::InvalidMoveException();
    std::string ris = std::string();
    ris.append(reinterpret_cast<const char *>(p->get_column() + 97));
    ris.append(reinterpret_cast<const char *>(p->get_row() + 48));
    ris.append(" ");
    ris.append(reinterpret_cast<const char *>(v[0] + 97));
    ris.append(reinterpret_cast<const char *>(v[1]+ 48));
    return ris;
}
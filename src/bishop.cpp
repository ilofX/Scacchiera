//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "bishop.h"

bishop::bishop(char name, short int c, short int r) : piece(name, c, r){}

bishop::bishop(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

vector<short int> bishop::ne_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> bishop::nw_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> bishop::se_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> bishop::sw_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

bool bishop::is_valid_final_pos(short int c, short int r){
    if(c < 0 || c > 7 || r < 0 || r > 7){
        return false;
    }
	if((abs(c-(this->get_column()))==(abs(r-(this->get_row()))))){
		return true;
	}else{
		return false;
	}
}

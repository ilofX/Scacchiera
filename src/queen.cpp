//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "queen.h"

queen::queen(char name, short int c, short int r) : piece(name, c, r){}

queen::queen(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

//queen::queen(const queen& k) : piece(k){}

//queen::queen(queen&& k) : piece(k){}

//queen& queen::operator=(const queen& k) : piece(k){}

//queen& queen::operator=(queen&& k) : piece(k){}

vector<short int> queen::n_move(){
    short int r = std::rand()%7;
    short int ec = get_column();
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> queen::ne_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> queen::e_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row();
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> queen::se_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> queen::s_move(){
    short int r = std::rand()%7;
    short int ec = get_column();
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> queen::sw_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> queen::w_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row();
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> queen::nw_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

bool queen::is_valid_final_pos(short int c, short int r){
    if(c < 0 || c > 7 || r < 0 || r > 7){
        return false;
    }
	if((c-(this->get_column()) == 0 && (r >= 0 && r <= 7)) || (r-(this->get_row()) == 0 && (c >= 0 && c <= 7)) || (abs(c-(this->get_column())) == abs(r-(this->get_row())))){
		return true;
	}else{
		return false;
	}
}

//
// Created by Nicolo' Tesser on 22/12/2021
//

#include "rook.h"

rook::rook(char name, short int c, short int r) : piece(name, c, r){}

rook::rook(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

/// <summary>
/// used to find a possible north move
/// </summary>
vector<short int> rook::n_move(){
    short int r = std::rand()%7;
    short int ec = get_column();
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible est move
/// </summary>
vector<short int> rook::e_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row();
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south move
/// </summary>
vector<short int> rook::s_move(){
    short int r = std::rand()%7;
    short int ec = get_column();
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible west move
/// </summary>
vector<short int> rook::w_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row();
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to check a movement final position for the specified piece (rook in this case)
/// </summary>
bool rook::is_valid_final_pos(short int c, short int r){
    if(c < 0 || c > 7 || r < 0 || r > 7){
        return false;
    }
	if((c-(this->get_column()) == 0 && (r >= 0 && r <= 7)) || (r-(this->get_row()) == 0 && (c >= 0 && c <= 7))){
		return true;
	}else{
		return false;
	}
}

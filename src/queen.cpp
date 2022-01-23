//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "queen.h"

queen::queen(char name, short int c, short int r) : piece(name, c, r){}

queen::queen(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

/// <summary>
/// used to find a possible north move
/// </summary>
vector<short int> queen::n_move(){
    short int r = std::rand()%7;
    short int ec = get_column();
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible north-est move
/// </summary>
vector<short int> queen::ne_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible est move
/// </summary>
vector<short int> queen::e_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row();
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south-est move
/// </summary>
vector<short int> queen::se_move(){
    short int r = std::rand()%7;
    short int ec = get_column() + r;
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south move
/// </summary>
vector<short int> queen::s_move(){
    short int r = std::rand()%7;
    short int ec = get_column();
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south-west move
/// </summary>
vector<short int> queen::sw_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row() + r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible west move
/// </summary>
vector<short int> queen::w_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row();
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible north-west move
/// </summary>
vector<short int> queen::nw_move(){
    short int r = std::rand()%7;
    short int ec = get_column() - r;
    short int er = get_row() - r;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to check a movement final position for the specified piece (queen in this case)
/// </summary>
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

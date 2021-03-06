//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "king.h"

king::king(char name, short int c, short int r) : piece(name, c, r){}

king::king(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

/// <summary>
/// used to find a possible north move
/// </summary>
vector<short int> king::n_move(){
    short int ec = get_column();
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible north-est move
/// </summary>
vector<short int> king::ne_move(){
    short int ec = get_column() + 1;
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible est move
/// </summary>
vector<short int> king::e_move(){
    short int ec = get_column() + 1;
    short int er = get_row();
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south-est move
/// </summary>
vector<short int> king::se_move(){
    short int ec = get_column() + 1;
    short int er = get_row() + 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south move
/// </summary>
vector<short int> king::s_move(){
    short int ec = get_column();
    short int er = get_row() + 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south-est move
/// </summary>
vector<short int> king::sw_move(){
    short int ec = get_column() - 1;
    short int er = get_row() + 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible west move
/// </summary>
vector<short int> king::w_move(){
    short int ec = get_column() - 1;
    short int er = get_row();
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible north move
/// </summary>
vector<short int> king::nw_move(){
    short int ec = get_column() - 1;
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to make the castling-est move
/// </summary>
vector<short int> king::castlingE_move(){
    short int ec, er;
    if(get_piece_name() == 'R'){
        ec = get_column() + 2;
        er = get_row();
    }else{
        ec = get_column() - 2;
        er = get_row();
    }
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible castling-west move
/// </summary>
vector<short int> king::castlingW_move(){
    short int ec, er;
    if(get_piece_name() == 'R'){
        ec = get_column() - 2;
        er = get_row();
    }else{
        ec = get_column() + 2;
        er = get_row();
    }
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to check a movement final position for the specified piece (king in this case)
/// </summary>
bool king::is_valid_final_pos(short int c, short int r){
	if((c-(this->get_column()) == 0 && abs(r-(this->get_row())) == 1) || (r-(this->get_row()) == 0 && abs(c-(this->get_column())) == 1) || (abs(c-(this->get_column())) == 1 && abs(r-this->get_row()) == 1) || (!(this->is_moved()) && r-(this->get_row()) == 0 && abs(c-(this->get_column())) == 2)){
			return true;
	}else{
		return false;
	}
}

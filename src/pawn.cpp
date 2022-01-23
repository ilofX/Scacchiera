//
// Created by Nicolo' Tesser on 22/12/2021
//
#include <iostream>
#include "pawn.h"

pawn::pawn(char name, short int c, short int r) : piece(name, c, r){}

pawn::pawn(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

/// <summary>
/// used to find a possible eat move
/// </summary>
vector<short int> pawn::eatE_move(){
    short int ec;
    short int er;
    if(get_piece_name() == 'P'){
        ec = get_column() + 1;
        er = get_row() - 1;
    }else{
        ec = get_column() - 1;
        er = get_row() + 1;
    }
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible eat move
/// </summary>
vector<short int> pawn::eatW_move(){
    short int ec;
    short int er;
    if(get_piece_name() == 'P'){
        ec = get_column() - 1;
        er = get_row() - 1;
    }else{
        ec = get_column() + 1;
        er = get_row() + 1;
    }
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible en passant move
/// </summary>
vector<short int> pawn::en_passantE_move(){
    short int ec;
    short int er;
    if(get_piece_name() == 'P'){
        ec = get_column() + 1;
        er = get_row();
    }else{
        ec = get_column() - 1;
        er = get_row();
    }
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible en passant move
/// </summary>
vector<short int> pawn::en_passantW_move(){
    short int ec;
    short int er;
    if(get_piece_name() == 'P'){
        ec = get_column() - 1;
        er = get_row();
    }else{
        ec = get_column() + 1;
        er = get_row();
    }
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible step move
/// </summary>
vector<short int> pawn::step_move(){
    short int r = 1 + rand()%2;
    short int ec, er;
    if(get_piece_name() == 'P'){
        ec = get_column();
        er = get_row() - r;
    }else{
        ec = get_column();
        er = get_row() + r;
    }
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to check a movement final position for the specified piece (pawn in this case)
/// </summary>
bool pawn::is_valid_final_pos(short int c, short int r){
    if(c < 0 || c > 7 || r < 0 || r > 7){
        return false;
    }
	if(this->get_piece_name() == 'P'){ //pezzo nero
		if((c-(this->get_column()) == 0 && r-(this->get_row()) == -1) || (abs(c-(this->get_column())) == 1 && r-(this->get_row()) == -1) || (!(this->is_moved()) && c-(this->get_column()) == 0 && r-(this->get_row()) == -2)){
			return true;
		}
	}else if(this->get_piece_name() == 'p'){ //pezzo bianco
		if((c-(this->get_column()) == 0 && r-(this->get_row()) == 1) || (abs(c-(this->get_column())) == 1 && r-(this->get_row()) == 1) || (!(this->is_moved()) && c-(this->get_column()) == 0 && r-(this->get_row()) == 2)){
			return true;
		}
	}
    return false;
}


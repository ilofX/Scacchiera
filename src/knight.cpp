//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "knight.h"

knight::knight(char name, short int c, short int r) : piece(name, c, r){}

knight::knight(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

/// <summary>
/// used to find a possible north-north-est move
/// </summary>
vector<short int> knight::nne_move(){
    short int ec = get_column() + 1;
    short int er = get_row() - 2;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible north-est-est move
/// </summary>
vector<short int> knight::nee_move(){
    short int ec = get_column() + 2;
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible north-north-west move
/// </summary>
vector<short int> knight::nnw_move(){
    short int ec = get_column() - 1;
    short int er = get_row() - 2;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible north-west-west move
/// </summary>
vector<short int> knight::nww_move(){
    short int ec = get_column() - 2;
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south-est-est move
/// </summary>

vector<short int> knight::see_move(){
    short int ec = get_column() + 2;
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south-south-est move
/// </summary>
vector<short int> knight::sse_move(){
    short int ec = get_column() + 1;
    short int er = get_row() + 2;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south-south-west move
/// </summary>
vector<short int> knight::ssw_move(){
    short int ec = get_column() - 1;
    short int er = get_row() + 2;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to find a possible south-west-west move
/// </summary>
vector<short int> knight::sww_move(){
    short int ec = get_column() - 2;
    short int er = get_row() + 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}

/// <summary>
/// used to check a movement final position for the specified piece (knight in this case)
/// </summary>
bool knight::is_valid_final_pos(short int c, short int r){
    if(c < 0 || c > 7 || r < 0 || r > 7){
        return false;
    }
	if((abs(r-(this->get_row()))==1 && abs(c-(this->get_column()))==2) || (abs(r-(this->get_row()))==2 && abs(c-(this->get_column()))==1)){
		return true;
	}else{
		return false;
	}
}

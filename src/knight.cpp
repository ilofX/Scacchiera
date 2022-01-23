//
// Created by Nicolo' Tesser on 22/12/2021
//
#include "knight.h"

knight::knight(char name, short int c, short int r) : piece(name, c, r){}

knight::knight(char name, short int c, short int r, int m, int lm) : piece(name, c, r, m, lm){}

//knight::knight(const knight& k) : piece(k){}

//knight::knight(knight&& k) : piece(k){}

//knight& knight::operator=(const knight& k) : piece(k){}

//knight& knight::operator=(knight&& k) : piece(k){}
/*
vector<short int> knight::nne_move(){
    short int ec = get_column() + 1;
    short int er = get_row() - 2;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> knight::nee_move(){
    short int ec = get_column() + 2;
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> knight::nnw_move(){
    short int ec = get_column() - 1;
    short int er = get_row() - 2;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> knight::nww_move(){
    short int ec = get_column() - 2;
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> knight::see_move(){
    short int ec = get_column() + 2;
    short int er = get_row() - 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> knight::sse_move(){
    short int ec = get_column() + 1;
    short int er = get_row() + 2;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> knight::ssw_move(){
    short int ec = get_column() - 1;
    short int er = get_row() + 2;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
vector<short int> knight::sww_move(){
    short int ec = get_column() - 2;
    short int er = get_row() + 1;
    vector<short int> v;
    v.push_back(ec);
    v.push_back(er);
    return v;
}
*/
bool knight::is_valid_final_pos(short int c, short int r){
	if((abs(r-(this->get_row()))==1 && abs(c-(this->get_column()))==2) || (abs(r-(this->get_row()))==2 && abs(c-(this->get_column()))==1)){
		return true;
	}else{
		return false;
	}
}

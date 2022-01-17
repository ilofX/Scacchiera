//
// Created by Nicol� Tesser on 22/12/2021
//
#include "human.h"
#include "piece.h"

human::human(char n, board& t) : player(n, t) {}

bool human::move(string s){
    bool flag = false;
    if(!is_valid_input(s)){
        throw InvalidMoveException();
    }else if(is_display_input(s)){
            this->scacchiera.print();
            throw InvalidMoveException();
            //break;
    }else{
        vector<short int> v = convert_input(s);
        this->scacchiera.move(v[0], v[1], v[2], v[3]);
    }

    return flag;
}

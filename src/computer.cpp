//
// Created by Nicolo Tesser on 22/12/2021
//
#include "computer.h"
#include "player.h"

computer::computer(char n, board& t) : player(n, t) {}

shared_ptr<piece> computer::get_random_piece(char c) {
    srand(time(0));
    if(c == 'b' || c == 'w' || c == 'B' || c == 'W'){
        vector<shared_ptr<piece>> v = this->scacchiera.getPieces(c);
        int r = std::rand()%(v.size());
        return v[r];
    }else{
        throw player::InvalidStateException();
    }
}

bool computer::is_human(){
    return false;
}

short int computer::get_random_col(shared_ptr<piece> p){
    srand(time(0));
    short int res, r;
    switch (p->get_piece_name()){
        case 'R':
        case 'r':
        case 'P':
        case 'p':
            r = -1 + std::rand()%3;
            res = r + p->get_column();
            break;

        case 'D':
        case 'd':
        case 'T':
        case 't':
        case 'A':
        case 'a':
            r = -7 + std::rand()%15;
            res = r + p->get_column();
            break;

        case 'C':
        case 'c':
            r = -2 + std::rand()%5;
            res = r + p->get_column();
            break;

    }

    return res;
}

short int computer::get_random_row(shared_ptr<piece> p){
    srand(time(0));
    short int res, r;
    switch (p->get_piece_name()){
        case 'R':
        case 'r':
            r = -1 + std::rand()%3;
            res = r + p->get_column();
            break;

        case 'D':
        case 'd':
        case 'T':
        case 't':
        case 'A':
        case 'a':
            r = -7 + std::rand()%15;
            res = r + p->get_column();
            break;

        case 'C':
        case 'c':
            r = -2 + std::rand()%5;
            res = r + p->get_column();
            break;

        case 'P':
            r = 0 + std::rand()%2;
            res = r + p->get_column();
            break;
        case 'p':
            r = -1 + std::rand()%2;
            res = r + p->get_column();
            break;

    }

    return res;
}

void computer::move(){
    shared_ptr<piece> p = get_random_piece(this->get_color());
    short int ec = get_random_col(p);
    short int er = get_random_row(p);
    this->scacchiera.move(p->get_column(), p->get_row(), ec, er);
}

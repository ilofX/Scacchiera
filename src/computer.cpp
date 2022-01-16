//
// Created by Nicol� Tesser on 22/12/2021
//
#include "computer.h"
#include "player.h"

computer::computer(char n, tabellone& t) : player(n, t) {}

shared_ptr<piece> computer::get_random_piece(bool b) {
    vector<shared_ptr<piece>> v = this->scacchiera.getPieces(b);
    int r = std::rand()%(v.size());
    return v[r];
}




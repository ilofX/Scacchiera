//
// Created by Nicol� Tesser on 22/12/2021
//
#include "computer.h"
#include "player.h"

computer::computer(char n, tabellone& t) : player(n, t) {}

<<<<<<< HEAD
shared_ptr<piece> computer::get_random_piece(char c) {
    if(n == 'b' || n == 'w' || n == 'B' || n == 'W'){
        vector<shared_ptr<piece>> v = this->scacchiera.getPieces(c);
        int r = std::rand()%(v.size());
        return v[r];
    }else{
        throw InvalidStateException();
    }
=======
shared_ptr<piece> computer::get_random_piece(bool b) {
    vector<shared_ptr<piece>> v = this->scacchiera.getPieces(b);
    int r = std::rand()%(v.size());
    return v[r];
>>>>>>> fe988a5bf16d9e6b0ec17fc6af627464842aa3a0
}

short int computer::get_random_col(shared_ptr<piece> p){
    switch (p->get_piece_name()){
        case 'R':
        case 'r':
            short int v[] = {-1,0,1};
            int r = std::rand()%3;
            return v[r] + p->get_column();

        case 'D':
        case 'd':
            short int[] = {-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7};
            int r = std::rand()%3;
            return v[r] + p->get_column();

        case 'T':
        case 't':
            short int[] = {-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7};
            int r = std::rand()%3;
            return v[r] + p->get_column();

        case 'A':
        case 'a':
            short int[] = {-7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7};
            int r = std::rand()%3;
            return v[r] + p->get_column();

        case 'C':
        case 'c':
            short int[] = {-2, -1, 0, 1, 2}
            int r = std::rand()%3;
            return v[r] + p->get_column();

        case 'P':
        case 'p':


        default:
            throw InvalidStateException();
}








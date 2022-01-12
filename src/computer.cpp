#include "computer.h"

computer::computer(char n, const tabellone& t) : player(n, t) {}

shared_ptr<piece> computer::get_random_piece(bool b) {
    if(this->color)
    vector<shared_ptr<piece>> v = this->scacchiera.getPieces(b);
    int r = std::rand()%(v.size());
    return v[r];
}




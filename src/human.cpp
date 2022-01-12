#include "human.h"

human::human(char n, const tabellone& t) : player(n, t) {}

bool human::move(string s){
    bool flag = false;
    if(!is_valid_input(s)){
        throw InvalidMoveException();
    }else if(is_display_move()){
            this->scacchiera.print();
            throw InvalidMoveException();
            //break;
    }else{
        vector<short int> v = convert_input(s);
        this->scacchiera.move(v[0], v[1], v[2], v[3]);
    }

    return flag;
}

//
// Created by Filippo Stella 2052644 on 22/12/2021.
//

#include <algorithm>
#include "tabellone.h"
#include "piece.h"


std::string tabellone::move(char startColumn, char startRow, char endColumn, char endRow) {
    return std::__cxx11::string();
}

std::string tabellone::print() {
    std::string ris;
    char matr[8][8] {' '};
    for(auto blackPiece=blackPieces.begin();blackPiece!=blackPieces.end();blackPiece++) {
        matr[(*blackPiece)->get_column()][(*blackPiece)->get_row()] = (*blackPiece)->get_piece_name();
    }
    for(auto whitePiece=whitePieces.begin();whitePiece!=whitePieces.end();whitePiece++){
        matr[(*whitePiece)->get_column()][(*whitePiece)->get_row()] = (*whitePiece)->get_piece_name();
    }
    for(int i=8; i>0; i--){
        ris+=to_string(i)+" ";
        for(int j=0;j<8;j++){
            ris+=matr[j][i];
        }
        ris+='\n';
    }
    ris+="ABCDEFGH";
    return ris;
}

std::string tabellone::promotion(char Column, char Row, char piece) {
    return std::__cxx11::string();
}

bool tabellone::hasNextMove() const {
    if(isTie()) throw MatchTiedException();
    if(isCheckmate(getKing(false))) throw CheckmateException();
    if(isCheckmate(getKing(true))) throw CheckmateException();
    return true;
}

bool tabellone::isTie() const {
    return false;
}

bool tabellone::isCheckmate(const shared_ptr<piece> king) const {
    return false;
}

bool tabellone::isCheck(char column, char row) const {
    return false;
}

bool tabellone::removePiece(char column, char row) {
    return false;
}

void tabellone::deleteHistory() {
    history.clear();
}

bool tabellone::canMove(piece& piece) const {
    return false;
}

const shared_ptr<piece> tabellone::getKing(bool isBlack) const {
    if(isBlack){
        for (auto iter = blackPieces.begin(); iter!=blackPieces.end(); iter++){
            if((*iter)->get_piece_name()=='K') return *iter;
        }
        throw InvalidStateException();
    }
    else{
        for (auto iter = whitePieces.begin(); iter!=whitePieces.end(); iter++){
            if((*iter)->get_piece_name()=='k') return *iter;
        }
        throw InvalidStateException();
    }
}

const shared_ptr<piece> tabellone::getPiece(char column, char row) {
    if(column>8 || row>8) throw IllegalCoordinatesException();

    for (auto iterB = blackPieces.begin(), iterW =  whitePieces.begin(); iterB != blackPieces.end() && iterW != whitePieces.end();){
        if(((*iterB)->get_column()== column) && ((*iterB)->get_row() == row)) return *iterB;
        if(((*iterW)->get_column() == column) && ((*iterW)->get_row() == row)) return *iterW;
        if(iterB != blackPieces.end()) iterB++;
        if(iterW != whitePieces.end()) iterW++;
    }

    throw IllegalCoordinatesException();
}

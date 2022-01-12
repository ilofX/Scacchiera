//
// Created by Filippo Stella 2052644 on 22/12/2021.
//

#include <algorithm>
#include "tabellone.h"
#include "piece.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"


void tabellone::move(short int startColumn, short int startRow, short int endColumn, short int endRow) {
    shared_ptr<piece> startPiece = getPiece(startColumn,startRow);
    if(startPiece==nullptr) throw IllegalCoordinatesException();
    if(!startPiece->is_valid_final_pos(endColumn,endRow)) throw IllegalCoordinatesException();
    shared_ptr<piece> endPiece = getPiece(endColumn,endRow);
    switch(startPiece->get_piece_name()){

        case 'P':
        case 'p':
            if(endRow==startRow && (std::max(endColumn,startColumn)-std::min(endColumn,startColumn))==1){   //En Passant implementation
                if(endPiece->get_moves()>1 || endPiece->get_last_moved()!=turn-1) throw IllegalMoveException();
                if(endPiece == nullptr) throw IllegalMoveException();
                removePiece(endPiece);
            }
            else if(endColumn!=startColumn){ //Eat piece
                if(endPiece==nullptr) throw IllegalMoveException();
                if(isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name())) throw IllegalMoveException();
                removePiece(endPiece);
            }
            else {  //Standard movement
                for (int i=(std::max(startRow,endRow)-std::min(startRow,endRow));i>=0;i--){
                    shared_ptr<piece> currentPiece = getPiece(startColumn,std::max(startRow,endRow)-i);
                    if(currentPiece!= nullptr) throw IllegalMoveException();
                }
                if(endRow==1 || endRow==8){ //Promotion after standard movement
                    startPiece->set_position(endColumn,endRow);
                    throw PromotionException();
                }
            }
            tieMoves=-1;
            break;

        case 'T':
        case 't':
            if(endColumn!=startColumn) {
                if (endColumn > startColumn) { //Horizontal-Right movement
                    for (char i=startColumn; i<endColumn; i++) {
                        shared_ptr<piece> currentPiece = getPiece(i, startRow);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
                else {  //Horizontal-Left movement
                    for (char i=startColumn; i>endColumn; i--) {
                        shared_ptr<piece> currentPiece = getPiece( i, startRow);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
            }
            else {
                if(endRow>startRow) { //Vertical-Top movement
                    for (char i = startRow; i<endRow; i++) {
                        shared_ptr<piece> currentPiece = getPiece(startColumn, i);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Vertical-Down movement
                    for (char i = startRow; i>endRow; i--) {
                        shared_ptr<piece> currentPiece = getPiece(startColumn, i);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
            }

            if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
            if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='K')) removePiece(endPiece);
            break;

        case 'C':
        case 'c':
            if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
            if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='K')) removePiece(endPiece);   //Eat Piece
            break;

        case 'A':
        case 'a':
            if(endRow>startRow){   //Top Movement
                if(endColumn>startColumn){   //Top-Right Movement
                    for(int i=0;i<(endRow-startRow)-1;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn+i,startRow+i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Top-Left Movement
                    for(int i=0;i<(endRow-startRow)-1;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn-i,startRow+i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
            }
            else{   //Bottom Movement
                if(endColumn>startColumn){   //Bottom-Right Movement
                    for(int i=0;i<(endColumn-startColumn)-1;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn+i,startRow-i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Bottom-Left Movement
                    for(int i=0;i<(endColumn-startColumn)-1;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn-i,startRow-i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
            }
            if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
            if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='K')) removePiece(endPiece);   //Eat Piece
            break;

        case 'D':
        case 'd':
            if(endColumn!=startColumn && startRow==endRow) { //Horizontal Movement
                if (endColumn > startColumn) { //Horizontal-Right movement
                    for (char i=startColumn; i<endColumn; i++) {
                        shared_ptr<piece> currentPiece = getPiece(i, startRow);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
                else {  //Horizontal-Left movement
                    for (char i=startColumn; i>endColumn; i--) {
                        shared_ptr<piece> currentPiece = getPiece( i, startRow);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
            }
            else if(endColumn==startColumn && endRow!=startRow){ //Vertical Movement
                if(endRow>startRow) { //Vertical-Top movement
                    for (char i = startRow; i<endRow; i++) {
                        shared_ptr<piece> currentPiece = getPiece(startColumn, i);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Vertical-Down movement
                    for (char i = startRow; i>endRow; i--) {
                        shared_ptr<piece> currentPiece = getPiece(startColumn, i);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
            }
            else if(endRow>startRow){   //Top Movement
                if(endColumn>startColumn){   //Top-Right Movement
                    for(int i=0;i<(endRow-startRow)-1;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn+i,startRow+i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Top-Left Movement
                    for(int i=0;i<(endRow-startRow)-1;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn-i,startRow+i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
            }
            else{   //Bottom Movement
                if(endColumn>startColumn){   //Bottom-Right Movement
                    for(int i=0;i<(endColumn-startColumn)-1;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn+i,startRow-i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Bottom-Left Movement
                    for(int i=0;i<(endColumn-startColumn)-1;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn-i,startRow-i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
            }

            if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
            if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='K')) removePiece(endPiece);   //Eat Piece
            break;

        case 'R':
        case 'r':
            if(startRow==endRow && endColumn-startColumn==2){   //Arrocco Lungo(Left)
                shared_ptr<piece> rightRook = getPiece(8,(startPiece->get_piece_name()>97) ? 1 : 8);
                if(startPiece->is_moved()) throw IllegalMoveException();
                if(rightRook!= nullptr && rightRook->is_moved()) throw IllegalMoveException();
                for(short int i=startColumn;i<rightRook->get_column();i++){
                    shared_ptr<piece> currPiece = getPiece(i,startRow);
                    if(currPiece!= nullptr) throw IllegalMoveException();
                }
                rightRook->set_position(endColumn-1,startRow);
            }
            else if(startRow==endRow && startColumn-endColumn==2){ //Arrocco Corto(Right)
                shared_ptr<piece> leftRook = getPiece(1,(startPiece->get_piece_name()>97) ? 1 : 8);
                if(startPiece->is_moved()) throw IllegalMoveException();
                if(leftRook!= nullptr && leftRook->is_moved()) throw IllegalMoveException();
                for(short int i=startColumn;i<leftRook->get_column();i++){
                    shared_ptr<piece> currPiece = getPiece(i,startRow);
                    if(currPiece!= nullptr) throw IllegalMoveException();
                }
                leftRook->set_position(endColumn-1,startRow);
            }
            else{   //Standard Movement
                if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
                if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='K')) removePiece(endPiece);
            }

            break;
        default:
            throw InvalidStateException();
    }
    startPiece->set_position(endColumn,endRow);
    startPiece->increment_move(turn);
    history.push_back(printHistory());
    turn++;
    tieMoves++;
}

std::string tabellone::print() {
    std::string ris;
    char matr[8][8] {' '};
    for(auto & blackPiece : blackPieces) {
        matr[blackPiece->get_column()-1][blackPiece->get_row()-1] = blackPiece->get_piece_name();
    }
    for(auto & whitePiece : whitePieces){
        matr[whitePiece->get_column()-1][whitePiece->get_row()-1] = whitePiece->get_piece_name();
    }
    for(int i=8; i>0; i--){
        ris+=to_string(i)+" ";
        for(auto & j : matr){
            ris+=j[i];
        }
        ris+='\n';
    }
    ris+="ABCDEFGH";
    return ris;
}

//Da modificare dopo adeguamento costruttori classi derivate di piece
std::shared_ptr<piece> tabellone::promotion(short int column, short int row, char pieceName) {
    shared_ptr<piece> piece = getPiece(column,row);
    if(piece->get_piece_name()!='P' || piece->get_piece_name()!='p') throw IllegalMoveException();
    switch (pieceName) {
        case 'D':
        case 'd':
            piece.reset(new queen(pieceName,piece->get_column(),piece->get_row(),piece->get_moves(), piece->get_last_moved()));
            break;
        case 'T':
        case 't':
            piece.reset(new rook(pieceName,piece->get_column(),piece->get_row(),piece->get_moves(), piece->get_last_moved()));
            break;
        case 'A':
        case 'a':
            piece.reset(new bishop(pieceName,piece->get_column(),piece->get_row(),piece->get_moves(), piece->get_last_moved()));
            break;
        case 'C':
        case 'c':
            piece.reset(new knight(pieceName,piece->get_column(),piece->get_row(),piece->get_moves(), piece->get_last_moved()));
            break;
        default:
            throw InvalidStateException();
    }
    deleteHistory();
    return piece;
}

bool tabellone::hasNextMove() const {
    std::vector<std::vector<shared_ptr<piece>>> board;



    if(isTie(board)) throw MatchTiedException();
    if(isCheckmate(getKing(false),board)) throw CheckmateException();
    if(isCheckmate(getKing(true),board)) throw CheckmateException();
    return true;
}

bool tabellone::isTie(std::vector<std::vector<shared_ptr<piece>>> &board) const {
    if(tieMoves>=50) return true;   //50 moves without moving pawns ore removing pieces
    if(std::count(history.begin(),history.end(),printHistory())>=3) return true; //same situation of the board for three times or more

    return false;
}

bool tabellone::isCheckmate(const shared_ptr<piece>& king, std::vector<std::vector<shared_ptr<piece>>> &board) const {
    return false;
}

bool tabellone::isCheck(short int column, short int row, char pieceName, std::vector<std::vector<std::shared_ptr<piece>>> &board) const {
    return false;
}

void tabellone::removePiece(short int column, short int row){
    shared_ptr<piece> piece = getPiece(column,row);
    if(piece->get_piece_name()>97){
        whitePieces.remove(piece);
    }
    else{
        blackPieces.remove(piece);
    }
    deleteHistory();
    tieMoves=-1;
}

void tabellone::removePiece(const std::shared_ptr<piece>& removePiece){
    if(removePiece->get_piece_name()>97){
        whitePieces.remove(removePiece);
    }
    else{
        blackPieces.remove(removePiece);
    }
    deleteHistory();
}

void tabellone::deleteHistory() {
    history.clear();
}

std::string tabellone::printHistory() const{
    std::string ris;
    for(const auto& piece : whitePieces){
        ris+=to_string(piece->get_piece_name())+ to_string(piece->get_column())+ to_string(piece->get_row());
    }
    for(const auto& piece : blackPieces){
        ris+=to_string(piece->get_piece_name())+ to_string(piece->get_column())+ to_string(piece->get_row());
    }
    return ris;
}

bool tabellone::canMove(shared_ptr<piece>) const {
    return false;
}

shared_ptr<piece> tabellone::getKing(bool isBlack) const {
    if(isBlack){
        for (const auto & blackPiece : blackPieces){
            if(blackPiece->get_piece_name()=='K') return blackPiece;
        }
        throw InvalidStateException();
    }
    else{
        for (const auto & whitePiece : whitePieces){
            if(whitePiece->get_piece_name()=='k') return whitePiece;
        }
        throw InvalidStateException();
    }
}

shared_ptr<piece> tabellone::getPiece(short int column, short int row) {
    if(column>8 || row>8) throw IllegalCoordinatesException();

    for (auto iterB = blackPieces.begin(), iterW =  whitePieces.begin(); iterB != blackPieces.end() && iterW != whitePieces.end();){
        if(((*iterB)->get_column()== column) && ((*iterB)->get_row() == row)) return *iterB;
        if(((*iterW)->get_column() == column) && ((*iterW)->get_row() == row)) return *iterW;
        if(iterB != blackPieces.end()) iterB++;
        if(iterW != whitePieces.end()) iterW++;
    }

    return nullptr;
}

std::vector<shared_ptr<piece>> tabellone::getPieces(bool isBlackPieces) const {
    std::vector<shared_ptr<piece>> ris;
    if(isBlackPieces)   std::copy(blackPieces.begin(), blackPieces.end(), ris.begin());
    else std::copy(whitePieces.begin(),whitePieces.end(), ris.begin());
    return ris;
}


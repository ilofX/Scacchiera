//
// Created by Filippo Stella 2052644 on 22/12/2021.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include "board.h"
#include "piece.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"
#include "king.h"

board::board() {
    turn=0;
    tieMoves=0;
    history = std::vector<std::string>();
    //Generating White Pieces
    whitePieces.push_back(std::shared_ptr<piece>{new king('r',3, 0)});
    whitePieces.push_back(std::shared_ptr<piece>{new queen('d',4,0)});
    whitePieces.push_back(std::shared_ptr<piece>{new rook('t',0,0)});
    whitePieces.push_back(std::shared_ptr<piece>{new rook('t',7,0)});
    whitePieces.push_back(std::shared_ptr<piece>{new knight('c',1,0)});
    whitePieces.push_back(std::shared_ptr<piece>{new knight('c',6,0)});
    whitePieces.push_back(std::shared_ptr<piece>{new bishop('a',2,0)});
    whitePieces.push_back(std::shared_ptr<piece>{new bishop('a',5,0)});
    //Generating Black Pieces
    blackPieces.push_back(std::shared_ptr<piece>{new king('R',3,7)});
    blackPieces.push_back(std::shared_ptr<piece>{new queen('D',4,7)});
    blackPieces.push_back(std::shared_ptr<piece>{new rook('T',0,7)});
    blackPieces.push_back(std::shared_ptr<piece>{new rook('T',7,7)});
    blackPieces.push_back(std::shared_ptr<piece>{new knight('C',1,7)});
    blackPieces.push_back(std::shared_ptr<piece>{new knight('C',6,7)});
    blackPieces.push_back(std::shared_ptr<piece>{new bishop('A',2,7)});
    blackPieces.push_back(std::shared_ptr<piece>{new bishop('A',5,7)});
    //Generating Pawns
    for(int i=0;i<8;i++){
        whitePieces.push_back(std::shared_ptr<piece>{new pawn('p',i,1)});
        blackPieces.push_back(std::shared_ptr<piece>{new pawn('P',i,6)});
    }
    history.push_back(printHistory());

    //change 8 on line 40 to 7 and uncomment the line below, this simulate a situation where blackPieces number != whitePieces number
    //an exception will be trown if you use the function getPiece()
    //so i changed the implementation of that function, the original is commented above the new one
    //whitePieces.push_back(std::shared_ptr<piece>{new pawn('p', 7, 1)});
}


bool board::move(short int startColumn, short int startRow, short int endColumn, short int endRow) {
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
                if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='k')) removePiece(endPiece);
            }
            else if(endColumn!=startColumn){ //Eat piece
                if(endPiece==nullptr) throw IllegalMoveException();
                if(isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name())) throw IllegalMoveException();
                if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='k')) removePiece(endPiece);
            }
            else {  //Standard movement
                if((std::max(startRow,endRow)-std::min(startRow,endRow))>=2 && startPiece->is_moved()) throw IllegalMoveException();
                if(startPiece->get_piece_name()=='P'){  //Moving Black pawn (Downwards Movement)
                    for (int i=startRow-1;i>=endRow;i--){
                        shared_ptr<piece> currentPiece = getPiece(startColumn,i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Moving White Pawn (Upper Movement)
                    for (int i=startRow+1;i<=endRow;i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn,i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }

                }
                if(endRow==0 || endRow==7){ //Promotion after standard movement
                    startPiece->set_position(endColumn,endRow);
                    pieceToPromote = startPiece;
                    throw PromotionException();
                }
            }
            tieMoves=-1;
            break;

        case 'T':
        case 't':
            if(endColumn!=startColumn) {
                if (endColumn > startColumn) { //Horizontal-Right movement
                    for (char i=startColumn+1; i<endColumn; i++) {
                        shared_ptr<piece> currentPiece = getPiece(i, startRow);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
                else {  //Horizontal-Left movement
                    for (char i=startColumn-1; i>endColumn; i--) {
                        shared_ptr<piece> currentPiece = getPiece( i, startRow);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
            }
            else {
                if(endRow>startRow) { //Vertical-Top movement
                    for (char i = startRow+1; i<endRow; i++) {
                        shared_ptr<piece> currentPiece = getPiece(startColumn, i);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Vertical-Down movement
                    for (char i = startRow-1; i>endRow; i--) {
                        shared_ptr<piece> currentPiece = getPiece(startColumn, i);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
            }

            if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
            if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='k')) removePiece(endPiece);
            break;

        case 'C':
        case 'c':
            if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
            if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='k')) removePiece(endPiece);   //Eat Piece
            break;

        case 'A':
        case 'a':
            if(endRow>startRow){   //Top Movement
                if(endColumn>startColumn){   //Top-Right Movement
                    for(int i=1;i<(endRow-startRow);i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn+i,startRow+i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Top-Left Movement
                    for(int i=1;i<(endRow-startRow);i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn-i,startRow+i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
            }
            else{   //Bottom Movement
                if(endColumn>startColumn){   //Bottom-Right Movement
                    for(int i=1;i<(endColumn-startColumn);i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn+i,startRow-i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Bottom-Left Movement
                    for(int i=1;i<(endColumn-startColumn);i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn-i,startRow-i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
            }
            if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
            if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='k')) removePiece(endPiece);   //Eat Piece
            break;

        case 'D':
        case 'd':
            if(endColumn!=startColumn && startRow==endRow) { //Horizontal Movement
                if (endColumn > startColumn) { //Horizontal-Right movement
                    for (char i=startColumn+1; i<endColumn; i++) {
                        shared_ptr<piece> currentPiece = getPiece(i, startRow);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
                else {  //Horizontal-Left movement
                    for (char i=startColumn-1; i>endColumn; i--) {
                        shared_ptr<piece> currentPiece = getPiece( i, startRow);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
            }
            else if(endColumn==startColumn && endRow!=startRow){ //Vertical Movement
                if(endRow>startRow) { //Vertical-Top movement
                    for (char i = startRow+1; i<endRow; i++) {
                        shared_ptr<piece> currentPiece = getPiece(startColumn, i);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Vertical-Down movement
                    for (char i = startRow-1; i>endRow; i--) {
                        shared_ptr<piece> currentPiece = getPiece(startColumn, i);
                        if (currentPiece != nullptr) throw IllegalMoveException();
                    }
                }
            }
            else if(endRow>startRow){   //Top Movement
                if(endColumn>startColumn){   //Top-Right Movement
                    for(int i=1;i<(endRow-startRow);i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn+i,startRow+i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Top-Left Movement
                    for(int i=1;i<(endRow-startRow);i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn-i,startRow+i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
            }
            else{   //Bottom Movement
                if(endColumn>startColumn){   //Bottom-Right Movement
                    for(int i=1;i<(endColumn-startColumn);i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn+i,startRow-i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
                else{   //Bottom-Left Movement
                    for(int i=1;i<(endColumn-startColumn);i++){
                        shared_ptr<piece> currentPiece = getPiece(startColumn-i,startRow-i);
                        if(currentPiece!= nullptr) throw IllegalMoveException();
                    }
                }
            }

            if(endPiece!= nullptr && (isupper(startPiece->get_piece_name())==isupper(endPiece->get_piece_name()))) throw IllegalMoveException();
            if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='k')) removePiece(endPiece);   //Eat Piece
            break;

        case 'R':
        case 'r':
            if(startRow==endRow && endColumn-startColumn==2){   //Arrocco Lungo(Right)
                shared_ptr<piece> rightRook = getPiece(7,(startPiece->get_piece_name()>=97) ? 0 : 7);
                if(startPiece->is_moved()) throw IllegalMoveException();
                if(rightRook!= nullptr && rightRook->is_moved()) throw IllegalMoveException();
                for(short int i=startColumn;i<rightRook->get_column();i++){
                    shared_ptr<piece> currPiece = getPiece(i,startRow);
                    if(currPiece!= nullptr) throw IllegalMoveException();
                }
                rightRook->set_position(endColumn-1,startRow);
            }
            else if(startRow==endRow && startColumn-endColumn==2){ //Arrocco Corto(Left)
                shared_ptr<piece> leftRook = getPiece(0,(startPiece->get_piece_name()>=97) ? 0 : 7);
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
                if(endPiece!= nullptr && (endPiece->get_piece_name()!='K' || endPiece->get_piece_name()!='k')) removePiece(endPiece);
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
    return true;
}

std::string board::print() {
    std::string ris;
    char matr[8][8];
    memset(matr,' ',sizeof(matr));
    ris+='\n';
    for(auto & blackPiece : blackPieces) {
        //Debug statement //std::cout << std::endl << "Pezzo: " << blackPiece->get_piece_name() << " colonna: " << blackPiece->get_column()-1 << " riga: " << blackPiece->get_row()-1 << std::endl;
        matr[blackPiece->get_column()][blackPiece->get_row()] = blackPiece->get_piece_name();
    }
    for(auto & whitePiece : whitePieces){
        matr[whitePiece->get_column()][whitePiece->get_row()] = whitePiece->get_piece_name();
    }
    for(int i=7; i>=0; i--){
        ris+=to_string(i+1)+" ";
        for(auto & j : matr){
            ris+=j[i];
        }
        ris+='\n';
    }
    ris+="\n  ABCDEFGH";
    return ris;
}

std::shared_ptr<piece> board::promotion(char pieceName) {
    if(pieceToPromote->get_piece_name() != 'P' || pieceToPromote->get_piece_name() != 'p') throw IllegalMoveException();
    switch (pieceName) {
        case 'D':
            pieceToPromote.reset(new queen(toupper(pieceName), pieceToPromote->get_column(), pieceToPromote->get_row(), pieceToPromote->get_moves(), pieceToPromote->get_last_moved()));
            break;
        case 'd':
            pieceToPromote.reset(new queen(tolower(pieceName), pieceToPromote->get_column(), pieceToPromote->get_row(), pieceToPromote->get_moves(), pieceToPromote->get_last_moved()));
            break;
        case 'T':
            pieceToPromote.reset(new rook(toupper(pieceName), pieceToPromote->get_column(), pieceToPromote->get_row(), pieceToPromote->get_moves(), pieceToPromote->get_last_moved()));
            break;
        case 't':
            pieceToPromote.reset(new rook(tolower(pieceName), pieceToPromote->get_column(), pieceToPromote->get_row(), pieceToPromote->get_moves(), pieceToPromote->get_last_moved()));
            break;
        case 'A':
            pieceToPromote.reset(new bishop(toupper(pieceName), pieceToPromote->get_column(), pieceToPromote->get_row(), pieceToPromote->get_moves(), pieceToPromote->get_last_moved()));
            break;
        case 'a':
            pieceToPromote.reset(new bishop(tolower(pieceName), pieceToPromote->get_column(), pieceToPromote->get_row(), pieceToPromote->get_moves(), pieceToPromote->get_last_moved()));
            break;
        case 'C':
            pieceToPromote.reset(new knight(toupper(pieceName), pieceToPromote->get_column(), pieceToPromote->get_row(), pieceToPromote->get_moves(), pieceToPromote->get_last_moved()));
            break;
        case 'c':
            pieceToPromote.reset(new knight(tolower(pieceName), pieceToPromote->get_column(), pieceToPromote->get_row(), pieceToPromote->get_moves(), pieceToPromote->get_last_moved()));
            break;
        default:
            throw InvalidStateException();
    }
    deleteHistory();
    pieceToPromote = nullptr;
    return pieceToPromote;
}

bool board::hasNextMove() const {
    std::vector<std::vector<shared_ptr<piece>>> board = std::vector<std::vector<shared_ptr<piece>>>(8,std::vector<shared_ptr<piece>>(8));
    for(auto & blackPiece : blackPieces) {
        board[blackPiece->get_column()][blackPiece->get_row()] = blackPiece;
    }
    for(auto & whitePiece : whitePieces){
        board[whitePiece->get_column()][whitePiece->get_row()] = whitePiece;
    }

    if(pieceToPromote!= nullptr) throw PromotionException();
    if(isTie(board)) throw MatchTiedException();
    if(isCheckmate(getKing(false),board)) throw CheckmateException();
    if(isCheckmate(getKing(true),board)) throw CheckmateException();
    return true;
}

bool board::isTie(std::vector<std::vector<shared_ptr<piece>>> &board) const {
    if(tieMoves>=50) return true;   //50 moves without moving pawns ore removing pieces
    if(std::count(history.begin(),history.end(),printHistory())>=3) return true; //same situation of the board for three times or more
    if((whitePieces.size()<3 && blackPieces.size()<2) || (blackPieces.size()<3 && whitePieces.size()<2)) return true; //insufficient pieces
    //Check For available moves
    int movablePieces=0;
    if(turn%2==1) {
        for(auto & blackPiece : blackPieces) {
            if(canMove(blackPiece,board)){
                movablePieces++;
                break;
            }
        }
    }
    else {
        for (auto &whitePiece: whitePieces) {
            if (canMove(whitePiece, board)) {
                movablePieces++;
                break;
            }
        }
    }
    if(movablePieces==0) return true;
    return false;
}

void board::removePiece(const std::shared_ptr<piece>& removePiece){
    if(removePiece->get_piece_name()>=97){
        whitePieces.remove(removePiece);
    }
    else{
        blackPieces.remove(removePiece);
    }
    deleteHistory();
}

void board::deleteHistory() {
    history.clear();
}

std::string board::printHistory() const{
    std::string ris;
    for(const auto& piece : whitePieces){
        ris+=to_string(piece->get_piece_name())+ to_string(piece->get_column())+ to_string(piece->get_row());
    }
    for(const auto& piece : blackPieces){
        ris+=to_string(piece->get_piece_name())+ to_string(piece->get_column())+ to_string(piece->get_row());
    }
    return ris;
}

shared_ptr<piece> board::getKing(bool isBlack) const {
    if(isBlack){
        if((blackPieces.front()->get_piece_name() != 'R')) throw InvalidStateException();
        return blackPieces.front();
    }
    else{
        if((whitePieces.front()->get_piece_name() != 'r')) throw InvalidStateException();
        return whitePieces.front();
    }
}

//shared_ptr<piece> board::getPiece(short int column, short int row) {
//    if(column>7 || row>7 || column<0 || row<0 ) throw IllegalCoordinatesException();
//
//    for (auto iterB = blackPieces.begin(), iterW =  whitePieces.begin(); iterB != blackPieces.end() && iterW != whitePieces.end();){
//        if(((*iterB)->get_column()== column) && ((*iterB)->get_row() == row)) return *iterB;
//        if(((*iterW)->get_column() == column) && ((*iterW)->get_row() == row)) return *iterW;
//        if(iterB != blackPieces.end()) iterB++;
//        if(iterW != whitePieces.end()) iterW++;
//    }
//
//    return nullptr;
//}

shared_ptr<piece> board::getPiece(short int column, short int row) {
    if (column < 0 || column > 7 || row < 0 || row > 7) throw IllegalCoordinatesException();

    for (shared_ptr<piece> piece : blackPieces) {
        if (piece->get_column() == column && piece->get_row() == row) return piece;
    }
    for (shared_ptr<piece> piece : whitePieces) {
        if (piece->get_column() == column && piece->get_row() == row) return piece;
    }

    return nullptr;
}

std::vector<shared_ptr<piece>> board::getPieces(char c) const {
    std::vector<shared_ptr<piece>> ris = std::vector<shared_ptr<piece>>((c == 'b' || c == 'B')?blackPieces.size():whitePieces.size());
    if(c == 'b' || c == 'B')   std::copy(blackPieces.begin(), blackPieces.end(), ris.begin());
    else std::copy(whitePieces.begin(),whitePieces.end(), ris.begin());
    return ris;
}

bool board::solvesCheck(short int startColumn, short int startRow, short int endColumn, short int endRow) {
    if((checkedPiece->get_column()==startColumn && checkedPiece->get_row()==startRow) && endColumn==startColumn+1 || endRow==startRow+1) return true; //The king Moves
    if((std::isupper(getPiece(startColumn,startRow)->get_piece_name())!=std::isupper(checkIssuerPiece->get_piece_name())) && (endColumn==checkIssuerPiece->get_column() && endRow==checkIssuerPiece->get_row())) return true; //The check Isuuer is removed
    //Check if between
    if(checkedPiece->get_column()==checkIssuerPiece->get_column()){ //Vertical Check
        if(endRow>std::min(checkedPiece->get_row(),checkIssuerPiece->get_row()) && endRow<std::max(checkedPiece->get_row(),checkIssuerPiece->get_row())) return true;
    }
    else if(checkedPiece->get_row()==checkIssuerPiece->get_row()){  //Horizontal Check
        if(endRow>std::min(checkedPiece->get_column(),checkIssuerPiece->get_column()) && endRow<std::max(checkedPiece->get_column(),checkIssuerPiece->get_column())) return true;
    }
    else {  //Oblique Check
        if(checkedPiece->get_row()<checkIssuerPiece->get_row()){    //Top-Oblique Check
            if(checkedPiece->get_column()<checkIssuerPiece->get_column()){  //Top-Right Check
                if(endRow>checkedPiece->get_row() && endColumn>checkedPiece->get_column() && endRow<checkIssuerPiece->get_row() && endColumn<checkIssuerPiece->get_column()) return true;
            }
            else{   //Top-left Check
                if(endRow>checkedPiece->get_row() && endColumn<checkedPiece->get_column() && endRow<checkIssuerPiece->get_row() && endColumn>checkIssuerPiece->get_column()) return true;
            }
        }
        else{
            if(checkedPiece->get_column()<checkIssuerPiece->get_column()){  //Bottom-Right check
                if(endRow<checkedPiece->get_row() && endColumn>checkedPiece->get_column() && endRow>checkIssuerPiece->get_row() && endColumn<checkIssuerPiece->get_column()) return true;
            }
            else{   //Bottom-left Check
                if(endRow>checkedPiece->get_row() && endColumn<checkedPiece->get_column() && endRow>checkIssuerPiece->get_row() && endColumn>checkIssuerPiece->get_column()) return true;
            }
        }
    }
    return false;
}

void board::clearCheck() {
    checkIssuerPiece = nullptr;
    checkedPiece = nullptr;
}

bool board::isEnemyPiece(const shared_ptr<piece> &piece1, const shared_ptr<piece> &piece2) {
    if(piece1 == nullptr || piece2 == nullptr) return false;
    if(std::isupper(piece1->get_piece_name())==std::isupper(piece2->get_piece_name())) return true;
    return false;
}


bool board::canMove(const shared_ptr<piece> &pieceToCheck, std::vector<std::vector<std::shared_ptr<piece>>> &board) const {
    if(pieceToCheck == nullptr) throw InvalidStateException();
    switch (pieceToCheck->get_piece_name()){
        case 'R':
        case 'r':
            //Non devo controllare per arrocco perchè comunque deve essere libera la casella adiacente al re per eseguire l'arrocco
        case 'D':
        case 'd':
            //Horizontal and Vertical checks
            if(board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row())==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()))) return true;
            if(board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row())==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()))) return true;
            if(board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()+1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()+1))) return true;
            if(board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()-1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()-1))) return true;
            //Oblique checks
            if(board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()-1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()-1))) return true;
            if(board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()+1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()+1))) return true;
            if(board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()-1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()-1))) return true;
            if(board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()+1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()+1))) return true;
            break;

        case 'T':
        case 't':
            if(board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row())==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()))) return true;
            if(board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row())==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()))) return true;
            if(board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()+1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()+1))) return true;
            if(board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()-1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()-1))) return true;
            break;

        case 'A':
        case 'a':
            if(board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()-1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()-1))) return true;
            if(board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()+1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()+1))) return true;
            if(board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()-1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()-1))) return true;
            if(board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()+1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()+1))) return true;
            break;
        case 'C':
        case 'c':
            if(board.at(pieceToCheck->get_column()+2).at(pieceToCheck->get_row()+1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+2).at(pieceToCheck->get_row()+1))) return true;
            if(board.at(pieceToCheck->get_column()+2).at(pieceToCheck->get_row()-1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+2).at(pieceToCheck->get_row()-1))) return true;
            if(board.at(pieceToCheck->get_column()-2).at(pieceToCheck->get_row()+1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-2).at(pieceToCheck->get_row()+1))) return true;
            if(board.at(pieceToCheck->get_column()-2).at(pieceToCheck->get_row()-1)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-2).at(pieceToCheck->get_row()-1))) return true;
            if(board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()-2)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()-2))) return true;
            if(board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()+2)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()+2))) return true;
            if(board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()-2)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()-2))) return true;
            if(board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()+2)==nullptr || isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()+2))) return true;
            break;

        case 'P':
            if(board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()-1)==nullptr) return true;
            if(isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()-1))) return true;
            if(isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()-1))) return true;
        case 'p':
            if(board.at(pieceToCheck->get_column()).at(pieceToCheck->get_row()+1)==nullptr) return true;
            if(isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()+1))) return true;
            if(isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()+1))) return true;

            if(isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()-1).at(pieceToCheck->get_row()))) return true;
            if(isEnemyPiece(pieceToCheck,board.at(pieceToCheck->get_column()+1).at(pieceToCheck->get_row()))) return true;
            break;

        default:
            throw InvalidStateException();
    }
    return false;
}

bool board::isBlackTurn() {
    return (this->turn%2);
}

bool board::isBlackToPromote() {
    return pieceToPromote->get_piece_name()<97;
}

bool board::isBlackUnderCheck() {
    return checkedPiece->get_piece_name()<97;
}

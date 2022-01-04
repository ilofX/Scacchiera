//
// Created by Filippo Stella 2052644 on 22/12/2021.
//

#ifndef TABELLONE_H
#define TABELLONE_H

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "piece.h"

class tabellone{
public:
    tabellone();
    //tabellone(Giocatore& whitePLayer, Giocatore& blackPlayer);

    //Copy Constructor
    tabellone(const tabellone& tab) = delete;
    //Copy Assignment
    tabellone& operator=(const tabellone& tab) = delete;

    //Move Constructor
    tabellone(tabellone&& tab);
    //Move Assignement
    tabellone& operator=(tabellone&& tab);

    class IllegalMoveException: public std::exception{};
    class IllegalCoordinatesException: public std::exception{};
    class MatchTiedException: public std::exception{};
    class InvalidStateException: public std::exception{};
    class CheckException: public std::exception{};
    class CheckmateException: public std::exception{};
    class PromotionException: public std::exception{};

    class findPiece{
    public:
        findPiece(char column, char row):column{column},row{row}{};
        bool operator() (piece Piece) const{
            return (Piece.get_row()==row && Piece.get_column()==column);
        }
    private:
        char column=0, row=0;
    };

    class findKing{
    public:
        findKing(char pieceName) :pieceName{pieceName}{};
        bool operator() (piece Piece) const{
            return Piece.get_piece_name()==pieceName;
        }
    private:
        char pieceName=0;
    };

    bool hasNextMove() const;
    std::string move(char startColumn, char startRow, char endColumn, char endRow);
    std::string promotion(char Column, char Row, char piece);

private:
    std::string print();
    const piece & getKing(bool isBlack) const;
    const piece& getPiece(char column, char row);
    bool canMove(piece& piece) const;
    bool isCheck(char column, char row) const;
    bool isCheckmate(const piece& king) const;
    bool isTie() const;
    bool removePiece(char column, char row);
    void deleteHistory();

    //Giocatore& whitePlayer, blackPlayer;
    std::list<piece> whitePieces, blackPieces;
    std::vector<std::string> history;
    int turn=-1;
};

#endif //TABELLONE_H

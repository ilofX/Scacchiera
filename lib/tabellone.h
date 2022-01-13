//
// Created by Filippo Stella 2052644 on 22/12/2021.
//

#ifndef TABELLONE_H
#define TABELLONE_H

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <memory>
#include "piece.h"


class tabellone{
public:
    tabellone();

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

    bool hasNextMove() const;
    void move(short int startColumn, short int startRow, short int endColumn, short int endRow);
    std::shared_ptr<piece> promotion(short int Column, short int Row, char piece);
    std::vector<shared_ptr<piece>> getPieces(bool isBlackPieces) const;
    std::string print();


private:
    std::string printHistory() const;
    shared_ptr<piece> getKing(bool isBlack) const;
    shared_ptr<piece> getPiece(short int column, short int row);
    bool canMove(shared_ptr<piece>) const;
    bool isCheck(short int column, short int row, char pieceName, std::vector<std::vector<std::shared_ptr<piece>>> &board) const;
    bool isCheckmate(const shared_ptr<piece> &king, std::vector<std::vector<shared_ptr<piece>>> &board) const;
    bool isTie(std::vector<std::vector<shared_ptr<piece>>> &board) const;
    void removePiece(const std::shared_ptr<piece>& removePiece);
    void deleteHistory();

    std::list<std::shared_ptr<piece>> whitePieces, blackPieces;
    std::vector<std::string> history;
    int turn=0, tieMoves=0;
};

#endif //TABELLONE_H

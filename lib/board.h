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


class board{
public:
    board();

    //Copy Constructor
    board(const board& tab) = default;
    //Copy Assignment
    board& operator=(const board& tab) = default;

    //Move Constructor
    board(board&& tab) = default;
    //Move Assignement
    board& operator=(board&& tab) = default;

    class IllegalMoveException: public std::exception{};
    class IllegalCoordinatesException: public std::exception{};
    class MatchTiedException: public std::exception{};
    class InvalidStateException: public std::exception{};
    class CheckException: public std::exception{};
    class CheckmateException: public std::exception{};
    class PromotionException: public std::exception{};

    bool hasNextMove() const;
    void move(short int startColumn, short int startRow, short int endColumn, short int endRow);
    std::shared_ptr<piece> promotion(char piece);
    std::vector<shared_ptr<piece>> getPieces(char c) const;
    bool isBlackTurn();
    bool isBlackToPromote();
    bool isBlackUnderCheck();
    std::string print();
    bool solvesCheck(short int startColumn, short int startRow, short int endColumn, short int endRow);
    void clearCheck();

    ~board() = default;

private:
    std::string printHistory() const;
    shared_ptr<piece> getKing(bool isBlack) const;
    shared_ptr<piece> getPiece(short int column, short int row);
    bool canMove(const shared_ptr<piece> &pieceToCheck, std::vector<std::vector<std::shared_ptr<piece>>> &board) const;
    bool isCheck(short int column, short int row, char pieceName, std::vector<std::vector<std::shared_ptr<piece>>> &board) const;
    bool isCheckmate(const shared_ptr<piece> &king, std::vector<std::vector<shared_ptr<piece>>> &board) const;
    bool isTie(std::vector<std::vector<shared_ptr<piece>>> &board) const;
    void removePiece(const std::shared_ptr<piece>& removePiece);
    void deleteHistory();
    static bool isEnemyPiece(const shared_ptr<piece>& piece1, const shared_ptr<piece>& piece2);

    std::list<std::shared_ptr<piece>> whitePieces, blackPieces;
    std::shared_ptr<piece> checkedPiece=nullptr, checkIssuerPiece=nullptr;
    std::shared_ptr<piece> pieceToPromote=nullptr;
    std::vector<std::string> history;
    int turn=0, tieMoves=0;
};

#endif //TABELLONE_H

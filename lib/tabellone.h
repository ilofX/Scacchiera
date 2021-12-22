//
// Created by Filippo Stella 2052644 on 22/12/2021.
//

#ifndef TABELLONE_H
#define TABELLONE_H

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

class tabellone{
public:
    tabellone();
    //tabellone(Giocatore& whitePLayer, Giocatore& blackPlayer);

    //Copy Constructor
    tabellone(const tabellone& tab);
    //Copy Assignment
    tabellone& operator=(const tabellone& tab);

    //Move Constructor
    tabellone(tabellone&& tab);
    //Move Assignement
    tabellone& operator=(tabellone&& tab);

    class IllegalMoveException: public std::exception{};
    class MatchTiedException: public std::exception{};
    class CheckException: public std::exception{};
    class CheckmateException: public std::exception{};

    std::string hasNextMove() const;
    std::string move(char startColumn, char startRow, char endColumn, char endRow);
    std::string promotion(char Column, char Row, char piece);

private:
    std::string print();
    bool isCheck(char column, char row) const;
    bool isCheckmate(char column, char row) const;
    bool isTie() const;
    bool removePiece(char cloumn, char row);
    std::vector<std::string> deleteHistory(std::vector<std::string>::iterator from, std::vector<std::string>::iterator to);

    //Giocatore& whitePlayer, blackPlayer;
    //std::list<Pezzo> whitePieces, blackPieces;
    std::vector<std::string> history;
    int turn=-1;
};

#endif //TABELLONE_H

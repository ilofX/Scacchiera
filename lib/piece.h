//
// Created by Nicol� Tesser on 22/12/2021
//
#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class piece{
	public:
		piece(char name, short int c, short int r);
        piece(char name, short int c, short int r, int m, int lm);
/*
		piece(const piece& p); //costruttore copia
		piece(piece&& p); //costruttore spostamento

		piece& operator=(const piece& p); //assegnamento copia
		piece& operator=(piece&& p); //assegnamento di spostamkento
*/
		short int get_column() const;
		short int get_row() const;
        int get_moves() const;
        int get_last_moved() const;
		void set_position(short int c, short int r);

		bool is_moved() const;
		void increment_move(int turn);

		char get_piece_name() const;
		void set_piece_name(char n);

		virtual bool is_valid_final_pos(short int c, short int r) = 0;

		//virtual ~piece() = 0;
    protected:
		int moves,last_moved;
		char piece_name; //il char permette anche la distinzione dei pezzi bianchi (lettere minuscole) da quelli neri (lettere maiuscole)
		short int column, row;
};

#endif

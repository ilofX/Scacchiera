#ifndef PIECE_H
#define PIECE_H

#include <string>

class piece{
	public:
		Piece(char col, short int r, short int c);
		virtual ~piece() = 0;
		
		bool is_same_color(const piece& p);
		virtual bool is_valid_move(char r, char c) = 0;
		
		char get_row();
		char get_column();
		void set_row(short int r);
		void set_column(short int c);
		
		virtual string to_string() = 0;
	private:
		char color;
		short int row;
		short int column;
}

#endif

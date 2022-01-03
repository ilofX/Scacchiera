#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <stdexcept>
#include <math>

class piece{
	public:
		piece(char name, bool m, short int c, short int r);

		piece(const piece& p); //costruttore copia
		piece(piece&& p); //costruttore spostamento

		piece& operator=(const piece& p); //assegnamento copia
		piece& operator=(piece&& p); //assegnamento di spostamkento

		short int[] get_position(); //il primo numero è l'indice colonna, il secondo quello riga
		void set_position(short int c, short int r);

		bool is_moved();
		void set_moved(bool m);

		char get_piece_name();
		void set_piece_name(char n);

		virtual bool is_valid_final_pos(short int c, short int r) = 0;

		string to_string();

		virtual ~piece() = 0;
	private:
		bool moved;
		char piece_name; //il char permette anche la distinzione dei pezzi bianchi (lettere maiuscole) da quelli neri (lettere minuscole)
		short int column;
		short int row;
}

#endif

#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <stdexcept>
#include <math>

class piece{
	public:
		piece(char name, short int r, short int c);

		piece(const piece& p); //costruttore copia
		piece(piece&& p); //costruttore spostamento
		
		piece& operator=(const piece& p); //assegnamento copia
		piece& operator=(piece&& p); //assegnamento di spostamkento
		
		short int[] get_position(); //il primo numero è l'indice colonna, il secondo quello riga
		void set_position(short int c, short int r); 
		
		virtual bool is_valid_final_pos(short int c, short int r) = 0;
		
		string to_string() = 0;
		
		virtual ~piece() = 0;
	private:
		char piece_name; //il char permette anche la distinzione dei pezzi bianchi (lettere maiuscole) da quelli neri (lettere minuscole)
		short int row;
		short int column;
}

#endif

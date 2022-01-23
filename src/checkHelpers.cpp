//
// Created by Francesca Damian
//

#include "board.h"

bool board::isCheckmate(shared_ptr<piece>& king, std::vector<std::vector<shared_ptr<piece>>>& board) {
	isCheck(king->get_column(), king->get_row(), king->get_piece_name(), board);
	return false;
}

bool board::isCheck(short int column, short int row, char pieceName, std::vector<std::vector<std::shared_ptr<piece>>>& board) {
	int king_column = column;
	int king_row = row;

	if (pieceName == 'r') {
		bool stop = false;
		for (int i = king_row + 1; i < 8 && stop == false; i++) {
			shared_ptr<piece> possibleThreat = board[king_column][i];
			if (possibleThreat == nullptr) continue;
			switch (possibleThreat->get_piece_name()) {
			case 't': case 'c': case 'a': case 'd': case 'p':
				stop = true;
				break;
			case 'T': case 'D':
				return true;
			}
		}
		stop = false;
		for (int i = king_row - 1; i >= 0 && stop == false; i--) {
			shared_ptr<piece> possibleThreat = board[king_column][i];
			if (possibleThreat == nullptr) continue;
			switch (possibleThreat->get_piece_name()) {
			case 't': case 'c': case 'a': case 'd': case 'p':
				stop = true;
				break;
			case 'T': case 'D':
				return true;
			}
		}
		stop = false;
		for (int i = king_column + 1; i < 8 && stop == false; i++) {
			shared_ptr<piece> possibleThreat = board[i][king_row];
			if (possibleThreat == nullptr) continue;
			switch (possibleThreat->get_piece_name()) {
			case 't': case 'c': case 'a': case 'd': case 'p':
				stop = true;
				break;
			case 'T': case 'D':
				return true;
			}
		}
		stop = false;
		for (int i = king_column - 1; i >= 0 && stop == false; i--) {
			shared_ptr<piece> possibleThreat = board[i][king_row];
			if (possibleThreat == nullptr) continue;
			switch (possibleThreat->get_piece_name()) {
			case 't': case 'c': case 'a': case 'd': case 'p':
				stop = true;
				break;
			case 'T': case 'D':
				return true;
			}
		}
		stop = false;
		for (int col = king_column + 1; col < 8 && stop == false; col++) {
			for (int row = king_row + 1; row < 8 && stop == false; row++) {
				shared_ptr<piece> possibleThreat = board[col][row];
				if (possibleThreat == nullptr) continue;
				switch (possibleThreat->get_piece_name()) {
				case 't': case 'c': case 'a': case 'd': case 'p':
					stop = true;
					break;
				case 'A': case 'D':
					return true;
				}
			}


		}
		stop = false;
		for (int col = king_column - 1; col >= 0 && stop == false; col--) {
			for (int row = king_row + 1; row < 8 && stop == false; row++) {
				shared_ptr<piece> possibleThreat = board[col][row];
				if (possibleThreat == nullptr) continue;
				switch (possibleThreat->get_piece_name()) {
				case 't': case 'c': case 'a': case 'd': case 'p':
					stop = true;
					break;
				case 'A': case 'D':
					return true;
				}
			}


		}
		stop = false;
		for (int col = king_column - 1; col >= 0 && stop == false; col--) {
			for (int row = king_row - 1; row >= 0 && stop == false; row--) {
				shared_ptr<piece> possibleThreat = board[col][row];
				if (possibleThreat == nullptr) continue;
				switch (possibleThreat->get_piece_name()) {
				case 't': case 'c': case 'a': case 'd': case 'p':
					stop = true;
					break;
				case 'A': case 'D':
					return true;
				}
			}


		}
		stop = false;
		for (int col = king_column + 1; col < 8 && stop == false; col++) {
			for (int row = king_row - 1; row >= 0 && stop == false; row--) {
				shared_ptr<piece> possibleThreat = board[col][row];
				if (possibleThreat == nullptr) continue;
				switch (possibleThreat->get_piece_name()) {
				case 't': case 'c': case 'a': case 'd': case 'p':
					stop = true;
					break;
				case 'A': case 'D':
					return true;
				}
			}


		}
	}
	else {

	}
	return false;
}

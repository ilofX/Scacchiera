//
// Created by Francesca Damian
//

#include "log_reader.h"

log_reader::log_reader(std::string file) {
	this->log_file.open(file);

	do {
		if (!getline(this->log_file, this->line)) throw IllegalLogFormatException();
	} while (!std::regex_match(line, log_start_regx));
}

log_reader::LINE_TYPE log_reader::load_next_line() {
	if (!getline(this->log_file, this->line)) {
		last_exception = "";
		last_promotion = '\0';
		return log_reader::END_OF_FILE;
	}
	if (std::regex_match(line, exception_regx)) {
		last_exception = line.substr(11, line.length());
		last_promotion = '\0';
		return log_reader::EXCEPTION;
	}
	if (std::regex_match(line, promotion_regx)) {
		last_exception = "";
		last_promotion = line[11];
		return log_reader::PROMOTION;
	}
	if (std::regex_match(line, move_regx)) {
		last_exception = "";
		last_promotion = '\0';
		this->calc_coords(line);
		return log_reader::MOVE;
	}
	else {
		last_exception = "";
		last_promotion = '\0';
		return log_reader::ERROR;
	}
}

std::string log_reader::get_line() {
	return this->line;
}

std::string log_reader::get_last_exception() {
	return this->last_exception;
}

char log_reader::get_last_promotion() {
	return this->last_promotion;
}

void log_reader::calc_coords(std::string move_str) {
		this->coords.clear();
		this->coords.push_back((int)move_str[0] - 97);
		this->coords.push_back((int)move_str[1] - 49);
		this->coords.push_back((int)move_str[3] - 97);
		this->coords.push_back((int)move_str[4] - 49);
}

/// <summary>
/// return a vector with origin column, origin row, destination column, destination row in this order
/// </summary>
/// <returns></returns>
std::vector<int> log_reader::get_coords() {
	return this->coords;
}
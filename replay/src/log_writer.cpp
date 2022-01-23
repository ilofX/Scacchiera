//
// Created by Francesca Damian
//

#include "log_writer.h"

log_writer::log_writer(std::string file) {
	this->output_file.open(file);
}

bool log_writer::write_game_state(std::string game_state) {
	this->output_file << game_state << std::endl;
	return true;
}

bool log_writer::write_exception(std::string exception) {
	this->output_file << "END OF GAME: " << std::endl;
	this->output_file << exception << std::endl;
	return true;
}
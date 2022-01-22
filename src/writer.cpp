//
// Created by Francesca Damian
//

#include "writer.h"

writer::writer(std::string file) {
	this->output_file.open(file);
	//print date and hour on first line
	auto time = std::chrono::system_clock::now();
	std::time_t data = std::chrono::system_clock::to_time_t(time);
	this->output_file << "Data log: " << std::ctime(&data) << std::endl;
	
	this->write_log_start();
}

/// <summary>
/// used to write to log file moves like [a2 a3] as "std::string move"
/// </summary>
/// <param name="move"></param>
/// <returns></returns>
bool writer::write_move(std::string move) {
	if (std::regex_match(move, visualizer_regx)) return false;
	if (!std::regex_match(move, move_regx)) throw IllegalWriterMoveException();

	move = move_formatter(move);

	this->output_file << move << std::endl;
	return true;
}

/// <summary>
/// used to write to log file fatal exceptions as "Exception: std::string exception"
/// </summary>
/// <param name="exception"></param>
/// <returns></returns>
bool writer::write_exception(std::string exception) {
	this->output_file << "Exception: " << exception << std::endl;
	return true;
}

/// <summary>
/// used to write to log file promotions so replay.exe knows what piece should be the promoted pawn as "Promotion: std::string promotion"
/// 
/// remember to have a valid move logged before writing a promotion or replay.exe will throw an exception
/// </summary>
/// <param name="promotion"></param>
/// <returns></returns>
bool writer::write_promotion(std::string promotion) {
	if (!std::regex_match(promotion, promotion_regx)) throw IllegalWriterPromotionException();
	this->output_file << "Promotion: " << promotion << std::endl;
	return true;
}

std::string writer::move_formatter(std::string unformatted_str) {
	std::string formatted_str = "";
	for (char c : unformatted_str) {
		formatted_str += tolower(c);
	}
	return formatted_str;
}

void writer::write_log_start() {
	this->output_file << "LOG START:" << std::endl;
}
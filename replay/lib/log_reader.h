//
// Created by Francesca Damian
//

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

class log_reader {
public:
	enum LINE_TYPE : int
	{
		START_OF_FILE = -1,
		END_OF_FILE = 0,
		PROMOTION = 1,
		EXCEPTION = 2,
		MOVE = 3,
		ERROR = 4
	};

	log_reader(std::string file);
	LINE_TYPE load_next_line();
	std::string get_line();
	std::string get_last_exception();
	char get_last_promotion();

	std::vector<int> get_coords();

	class IllegalLogFormatException : public std::exception {};
	//class IllegalStateException : public std::exception {};
private:
	std::ifstream log_file;
	std::string line;
	std::string last_exception;
	char last_promotion;

	std::vector<int> coords;

	std::regex log_start_regx{ "LOG START:" };
	std::regex exception_regx{ "Exception: [a-zA-Z' ']*" };
	std::regex promotion_regx{ "Promotion: [tTcCaAdD]" };
	std::regex move_regx{ "[a-hA-H][1-8][' '][a-hA-H][1-8]" };

	void calc_coords(std::string move_str);
};
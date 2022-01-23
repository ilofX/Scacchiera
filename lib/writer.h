//
// Created by Francesca Damian
//

#ifndef WRITER_H
#define WRITER_H

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <chrono>
#include <ctime>

class writer {
public:
    writer(std::string file);

    bool write_move(std::string move);
    bool write_exception(std::string exception);
    bool write_promotion(std::string promotion);
    
    class IllegalWriterMoveException : public std::exception {};
    class IllegalWriterPromotionException : public std::exception {};
private:
    std::ofstream output_file;
    std::regex visualizer_regx{ "[xX][xX][' '][xX][xX]" };
    std::regex move_regx{ "[a-hA-H][1-8][' '][a-hA-H][1-8]" };
    std::regex promotion_regx{ "[tTcCaAdD]" };

    std::string move_formatter(std::string unformatted_str);
    void write_log_start();
};

#endif
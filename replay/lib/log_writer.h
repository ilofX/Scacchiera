//
// Created by Francesca Damian
//

#ifndef LOG_WRITER_H
#define LOG_WRITER_H

#include <iostream>
#include <string>
#include <fstream>

class log_writer {
public:
    log_writer(std::string file);

    bool write_game_state(std::string game_state);
    bool write_exception(std::string exception);
private:
    std::ofstream output_file;
};

#endif
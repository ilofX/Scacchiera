//
// Created by Francesca Damian
//

#include <iostream>
#include <chrono>
#include <thread>

#include "board.h"
#include "log_reader.h"
#include "log_writer.h"

#define pause(t) this_thread::sleep_for(chrono::milliseconds(t))
#define PAUSE_DELAY_MS 1000

int main(int argc, char* argv[]) {
    string replayType;
    string replayFileStr;
    string replayLogStr;
    bool logOnFile = false;

    try {
        if (argc < 3 || argc > 4) {
            throw std::invalid_argument("numero di argomenti non supportato");
        }
        replayType = argv[1];

        if (replayType.compare("v") == 0 && argc == 3) {
            replayFileStr = argv[2];
        }
        else if (replayType.compare("f") == 0 && argc == 4) {
            logOnFile = true;
            replayFileStr = argv[2];
            replayLogStr = argv[3];
        }
        else {
            throw std::invalid_argument("numero o tipo di argomento non supportato");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
        exit(-2);
    }
    board tabellone = board();

    log_writer writer = log_writer(replayLogStr);
    log_reader reader = log_reader(replayFileStr);
    log_reader::LINE_TYPE last_line_type = log_reader::LINE_TYPE::START_OF_FILE;
    vector<int> coords;

    last_line_type = reader.load_next_line();
    while (last_line_type != log_reader::END_OF_FILE) {
        try {
            if (last_line_type == log_reader::LINE_TYPE::EXCEPTION) {
                std::cout << "Partita terminata precocemente a causa di un'eccezione: \n";
                std::cout << reader.get_last_exception() << std::endl;
                exit(5);
            }
            if (last_line_type == log_reader::LINE_TYPE::PROMOTION) {
                //std::cout << "Promozione: " << reader.get_last_promotion() << std::endl;
            }
            if (last_line_type == log_reader::LINE_TYPE::ERROR) {
                exit(10);
            }
            if (last_line_type == log_reader::LINE_TYPE::MOVE) {
                coords = reader.get_coords();
                tabellone.move(coords[0], coords[1], coords[2], coords[3]);
                if(!logOnFile) std::cout << tabellone.print() << std::endl;
                else {
                    writer.write_game_state(tabellone.print());
                }
            }
            last_line_type = reader.load_next_line();
            if (!logOnFile) pause(PAUSE_DELAY_MS);
        }
        catch (board::PromotionException& ex) {
            last_line_type = reader.load_next_line();
            tabellone.promotion(reader.get_last_promotion());
        }
    }
    return 0;
}
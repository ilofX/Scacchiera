#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include "board.h"
#include "player.h"
#include "computer.h"
#include "human.h"
#include "writer.h"

int main(int argc, char* argv[]) {
    srand(time(nullptr));

    board tabellone = board();
    unique_ptr<player> whitePlayer, blackPlayer;
    writer logger = writer(std::string("log.txt"));

    //Argument checking
    if(argc<2 || argc>3){
        exit(1);
    }
    //players creation
    if(argv[1][0]=='-' && argv[1][1]=='c' && argv[1][2]=='c'){ //Computer vs Computer
        //Debug statement std::cout << "Computer vs Computer" << std::endl;
        whitePlayer = std::make_unique<computer>('W', tabellone);
        blackPlayer = std::make_unique<computer>('B', tabellone);

    }
    else if(argv[1][0]=='-' && argv[1][1]=='p' && argv[1][2]=='c'){ //Player vs Computer
        //Debug statement std::cout << "Human vs Computer" << std::endl;
        if(std::rand()%2==1){
            std::cout << "Al giocatore umano sono stati assegnati i pezzi BIANCHI" << std::endl;
            whitePlayer = std::make_unique<human>('W', tabellone);
            blackPlayer = std::make_unique<computer>('B', tabellone);
        }
        else{
            std::cout << "Al giocatore umano sono stati assegnati i pezzi NERI" << std::endl;
            whitePlayer = std::make_unique<computer>('W', tabellone);
            blackPlayer = std::make_unique<human>('B', tabellone);
        }
    }
    else{
        std::cout << "Parametri di input non validi" << std::endl;
        exit(2);
    }
    //Board Construction
    std::cout << tabellone.print() << std::endl;

    //Match Loop

    try {
        std::string input;
        while (tabellone.hasNextMove()) {
            input = "";
            try {
                if(tabellone.isBlackTurn()){ //Turno del giocatore NERO
                    std::cout << "Muove il giocatore NERO" << std::endl;
                    if(blackPlayer->is_human()){    //Il giocatore NERO è umano
                        std::cout << "inserire le coordinate: ";
                        getline(cin,input);
                        input = blackPlayer->move(input, false);
                    }
                    else {  //Il giocatore NERO è un computer
                        input = blackPlayer->move(input, false);
                    }
                }
                else{   //Turno del giocatore BIANCO
                    std::cout << "Muove il giocatore BIANCO" << std::endl;
                    if(whitePlayer->is_human()){   //Il giocatore BIANCO è un umano
                        std::cout << "inserire le coordinate: ";
                        getline(cin,input);
                        input = whitePlayer->move(input, false);
                    }
                    else{   //Il giocaore BIANCO è un computer
                        input = whitePlayer->move(input, false);
                    }
                }
                logger.write_move(input);
            }
            catch (player::InvalidInputException &ex){
                std::cout << "La stringa inserita non e valida" << std::endl;
                logger.write_exception("La stringa inserita non e valida");
                continue;
            }
            catch (player::InvalidMoveException &ex){
                std::cout << "Il computer non e riuscito a muovere, nuovo tentativo" << std::endl;
                logger.write_exception("Il computer non e riuscito a muovere, nuovo tentativo");
                continue;
            }
            catch (board::IllegalMoveException &ex) {
                std::cout << "La mossa richiesta non e valida" << std::endl;
                logger.write_exception("La mossa richiesta non e valida");
                continue;
            }
            catch (board::IllegalCoordinatesException &ex) {
                std::cout << "Le coordinate inserite non sono valide" << std::endl;
                logger.write_exception("Le coordinate inserite non sono valide");
                continue;
            }
            catch (board::CheckException &ex) {
                if(tabellone.isBlackUnderCheck()){ //Black player is in a checked state
                    std::cout << "Il re NERO è in scacco" << std::endl;

                    if(blackPlayer->is_human()){    //Black player is human
                        bool done = false;
                        while(!done) {
                            input = "";
                            std::cout << "inserire la mossa per uscire dallo scacco: ";
                            getline(cin, input);
                            try{
                                input = blackPlayer->move(input, true);
                            }
                            catch(player::InvalidInputException &ex){
                                std::cout << "La Mossa richiesta non risolve lo scacco, riprovare" << std::endl;
                                done = false;
                                continue;
                            }
                            done = true;
                        }
                        logger.write_move(input);
                    }
                    else{
                        bool done = false;
                        while(!done) {
                            input = "";
                            try{
                                input = blackPlayer->move(input, true);
                            }
                            catch(player::InvalidInputException &ex){
                                std::cout << "La Mossa richiesta non risolve lo scacco, riprovare" << std::endl;
                                done = false;
                                continue;
                            }
                            done = true;
                        }
                        logger.write_move(input);
                    }
                }
                else{ // White player is in checked state
                    std::cout << "Il re BIANCO è in scacco" << std::endl;

                    if(whitePlayer->is_human()){ //White player is human
                        bool done = false;
                        while(!done) {
                            input = "";
                            std::cout << "inserire la mossa per uscire dallo scacco: ";
                            getline(cin, input);
                            try{
                                input = whitePlayer->move(input, true);
                            }
                            catch(player::InvalidInputException &ex){
                                std::cout << "La Mossa richiesta non risolve lo scacco, riprovare" << std::endl;
                                done = false;
                                continue;
                            }
                            done = true;
                        }
                        logger.write_move(input);
                    }
                    else{   //White player is a computer
                        bool done = false;
                        while(!done) {
                            input = "";
                            try{
                                input = whitePlayer->move(input, true);
                            }
                            catch(player::InvalidInputException &ex){
                                std::cout << "La Mossa richiesta non risolve lo scacco, riprovare" << std::endl;
                                done = false;
                                continue;
                            }
                            done = true;
                        }
                        logger.write_move(input);
                    }
                }
            }
            catch (board::PromotionException &ex) {
                //Get promotion piece selection
                input="";
                if((tabellone.isBlackToPromote() && blackPlayer->is_human()) || (!tabellone.isBlackToPromote() && whitePlayer->is_human())){ //The piece to promote is the one of a human player
                    std::cout << "Con che pezzo si vuole promuovere il pedone?\n C=cavallo | T=torre | A=alfiere | D=regina\n Inserire la selezione: ";
                    getline(cin,input);
                }
                else{   //the piece to promote is the one of a computer
                    if(tabellone.isBlackToPromote()){ //Computer is blackPlayer
                       input = (dynamic_cast<computer&>(*blackPlayer)).get_random_piece_to_promote(blackPlayer->get_color());
                    }
                    else{   //Computer is whitePlayer
                        input = (dynamic_cast<computer&>(*whitePlayer)).get_random_piece_to_promote(whitePlayer->get_color());
                    }
                }
                shared_ptr<piece> newPiece =  tabellone.promotion(input[0]);

                std::string ris;
                ris.append(reinterpret_cast<const char *>(newPiece->get_column() + 97));
                ris.append(reinterpret_cast<const char *>(newPiece->get_row() + 48));
                ris.append(input);
                logger.write_promotion(ris);
            }
            catch (board::InvalidStateException &ex) {
                std::cout << "La partita ha raggiunto uno stato inconsistente, terminato" << std::endl;
                logger.write_exception("La partita ha raggiunto uno stato inconsistente, terminato");
                exit(-1);
            }
        }
    }
    catch (board::InvalidStateException &ex) {
        std::cout << "La partita ha raggiunto uno stato inconsistente, terminato" << std::endl;
        logger.write_exception("La partita ha raggiunto uno stato inconsistente, terminato");
        exit(-1);
    }
    catch (board::CheckmateException &ex) {
        std::cout << "La partita e terminata per scacco matto" << std::endl;
        logger.write_exception("La partita e terminata per scacco matto");
        exit(40);
    }
    catch (board::MatchTiedException &ex) {
        std::cout << "La partita e terminata per parità" << std::endl;
        logger.write_exception("La partita e terminata per parità");
        exit(50);
    }
    return 0;
}

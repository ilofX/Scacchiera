#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include "board.h"
#include "player.h"
#include "computer.h"
#include "human.h"

int main(int argc, char* argv[]) {
    srand(time(nullptr));

    board tabellone = board();
    unique_ptr<player> whitePlayer, blackPlayer;

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
        //if(std::rand()%2==1){
        if(true){
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

    std::string input;
    try {
        while (tabellone.hasNextMove()) {
            input = "";
            try {
                if(tabellone.isBlackTurn()){ //Turno del giocatore NERO
                    std::cout << "Muove il giocatore NERO" << std::endl;
                    if(blackPlayer->is_human()){    //Il giocatore NERO è umano
                        std::cout << "inserire le coordinate: ";
                        getline(cin,input);
                        blackPlayer->move(input);
                    }
                    else {  //Il giocatore NERO è un computer
                        blackPlayer->move(input);
                    }
                }
                else{   //Turno del giocatore BIANCO
                    std::cout << "Muove il giocatore BIANCO" << std::endl;
                    if(whitePlayer->is_human()){   //Il giocatore BIANCO è un umano
                        std::cout << "inserire le coordinate: ";
                        getline(cin,input);
                        whitePlayer->move(input);
                    }
                    else{   //Il giocaore BIANCO è un computer
                        whitePlayer->move(input);
                    }
                }
            }
            catch (player::InvalidInputException &ex){
                std::cout << "La stringa inserita non e valida" << std::endl;
                continue;
            }
            catch (player::InvalidMoveException &ex){
                std::cout << "Il computer non e riuscito a muovere, nuovo tentativo" << std::endl;
                continue;
            }
            catch (board::IllegalMoveException &ex) {
                std::cout << "La mossa richiesta non e valida" << std::endl;
                continue;
            }
            catch (board::IllegalCoordinatesException &ex) {
                std::cout << "Le coordinate inserite non sono valide" << std::endl;
                continue;
            }
            catch (board::CheckException &ex) {
                try { //Attempt possible solution
                    if(tabellone.isBlackUnderCheck()){
                        if(blackPlayer->is_human()){

                        }
                        else{

                        }
                    }
                    else{
                        if(whitePlayer->is_human()){

                        }
                        else{

                        }
                    }
                    //if(tabellone.solvesCheck(startColumn, startRow, endColumn, endRow)) tabellone.move(startColumn, startRow, endColumn, endRow);
                }
                catch(board::IllegalMoveException& ex){
                    throw board::CheckException();
                }
            }
            catch (board::PromotionException &ex) {
                //Get promotion piece selection
                std::string input;
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
                tabellone.promotion(input[0]);
            }
            catch (board::InvalidStateException &ex) {
                std::cout << "La partita ha raggiunto uno stato inconsistente, terminato" << std::endl;
                exit(-1);
            }
        }
    }
    catch (board::InvalidStateException &ex) {
        std::cout << "La partita ha raggiunto uno stato inconsistente, terminato" << std::endl;
        exit(-1);
    }
    catch (board::CheckmateException &ex) {
        std::cout << "La partita e terminata per scacco matto" << std::endl;
        exit(40);
    }
    catch (board::MatchTiedException &ex) {
        std::cout << "La partita e terminata per parità" << std::endl;
        exit(50);
    }
    return 0;
}

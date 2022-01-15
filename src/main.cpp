#include <iostream>
#include <string>
#include "tabellone.h"
#include "player.h"


int main(int argc, char* argv[]) {
    //Argument checking
    if(argc<1 || argc>2){
        exit(1);
    }
    std::cout << argv[0];
    //players creation
    if(argv[0][0]=='c' && argv[0][1]=='c'){ //Computer vs Computer

    }
    else if(argv[0][0]=='p' && argv[0][1]=='c'){ //Player vs Computer

    }
    else{
        exit(2);
    }
    //Board Construction
    tabellone board = tabellone();
    //Match Loop
    try {
        while (board.hasNextMove()) {

            try {

            }
            catch (tabellone::IllegalMoveException &ex) {
                std::cout << "La mossa richiesta non è valida" << std::endl;
                continue;
            }
            catch (tabellone::IllegalCoordinatesException &ex) {
                std::cout << "Le coordinate inserite non sono valide" << std::endl;
                continue;
            }
            catch (tabellone::CheckException &ex) {
                try { //Attempt possible solution
                    //get move

                    //if(board.solvesCheck(startColumn, startRow, endColumn, endRow)) move(startColumn, startRow, endColumn, endRow);
                }
                catch(tabellone::IllegalMoveException& ex){
                    throw tabellone::CheckException();
                }
            }
            catch (tabellone::PromotionException &ex) {
                //Get promotion piece selection

                //board.promotion(endColumn, endRow, promotion);
            }
            catch (tabellone::InvalidStateException &ex) {
                std::cout << "La partita ha raggiunto uno stato inconsistente, terminato" << std::endl;
                exit(-1);
            }

        }
    }
    catch (tabellone::CheckmateException &ex) {
        std::cout << "La partita è terminata per scacco matto" << std::endl;
        exit(40);
    }
    catch (tabellone::MatchTiedException &ex) {
        std::cout << "La partita è terminata per parità" << std::endl;
        exit(50);
    }
    return 0;
}

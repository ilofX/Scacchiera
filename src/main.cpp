#include <iostream>
#include "tabellone.h"
#include "player.h"

int main() {
    tabellone board = tabellone();

    try {
        while (board.hasNextMove()) {

            try {

            }
            catch (tabellone::IllegalMoveException &ex) {

            }
            catch (tabellone::IllegalCoordinatesException &ex) {

            }
            catch (tabellone::CheckException &ex) {
                try { //Attempt possible solution
                    //move(startColumn, startRow, endColumn, endRow);
                }
                catch(tabellone::IllegalMoveException& ex){
                    return false;
                }
            }
            catch (tabellone::PromotionException &ex) {

            }

            catch (tabellone::InvalidStateException &ex) {

            }

        }
    }
    catch (tabellone::CheckmateException &ex) {

    }
    catch (tabellone::MatchTiedException &ex) {

    }
    return 0;
}

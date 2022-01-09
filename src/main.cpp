#include <iostream>
#include "tabellone.h"

int main() {
    tabellone board;

    try {
        while (board.hasNextMove()) {

            try {

            }
            catch (tabellone::IllegalMoveException &ex) {

            }
            catch (tabellone::IllegalCoordinatesException &ex) {

            }
            catch (tabellone::CheckException &ex) {

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

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

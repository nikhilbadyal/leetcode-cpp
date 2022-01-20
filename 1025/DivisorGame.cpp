//
// Created by Nikhil on 31-05-2021.
//

#include "DivisorGame.h"

bool DivisorGame::divisorGame(int n) {
    bool solution = false;
    int aliceTurn = 1;
    while (n >= 0) {
        aliceTurn++;
        bool choiceMade = false;
        for (int i = 1; i < n; ++i) {
            if (n % i == 0) {
                n = n - i;
                choiceMade = true;
            }
        }
        if (!choiceMade) {
            if (aliceTurn % 2 == 0) {
                return false;
            }
            return true;
        }
    }
    if (n == 0 && aliceTurn % 2 == 0) {
        return true;
    }

    return solution;
}

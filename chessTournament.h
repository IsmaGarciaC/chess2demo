#pragma once
#include <iostream>
#include <set>
#include <cmath>
#include "game.h"
#include "bSearchTreeType.h"

using namespace std;

template <int N>
class ChessTournament {
private:
    BSearchTreeType games;
    string name;
    int num_rounds = N;

public:
    string getName();
    int getNumRounds();
    void insertGame(Game p);
    void show();

    static int keys[(int)pow(2, N) - 1];
    static int current_round;
    static void keysGames();

    ChessTournament();
};

template <int N>
int ChessTournament<N>::keys[];

template <int N>
int ChessTournament<N>::current_round = 0;

template <int N>
ChessTournament<N>::ChessTournament() {
    keysGames();
}

template <int N>
string ChessTournament<N>::getName() { 
    return name; 
}

template <int N>
int ChessTournament<N>::getNumRounds() { 
    return num_rounds; 
}

template <int N>
void ChessTournament<N>::insertGame(Game p) {
    current_round++;
    p.setKey(keys[current_round]);
    games.insert(p);
}

template <int N>
void ChessTournament<N>::show() { 
    games.postOrder(); 
}

template <int N>
void ChessTournament<N>::keysGames() {
    int numRounds = N;
    set<int> indexes_used;
    int limit = (int)pow(2, numRounds) - 1;
    int n = numRounds - 1;

    int i = 0;
    int index = (int)pow(2, n);

    keys[i++] = index;
    indexes_used.insert(index);
    while (n > 0) {
        n = n - 1;

        int j = 1;
        index = j * (int)pow(2, n);
        if (indexes_used.find(index) == indexes_used.end()) {
            keys[i++] = index;
            indexes_used.insert(index);
        }

        while (index <= limit) {
            if (indexes_used.find(index) == indexes_used.end()) {
                keys[i++] = index;
                indexes_used.insert(index);
            }
            j++;
            index = j * (int)pow(2, n);
        }
    }
}

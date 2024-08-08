#include <iostream>
#include <filesystem>
#include "coordinates.h"
#include "board.h"
#include "piece.h"
#include "square.h"
#include "game.h"
#include "chessTournament.h"

int main() {
    // Four levels of games - Final, Semi Final, Quarter Final and Pre-Quarter Finals
ChessTournament<4> trn;

trn.insertGame(Game("p1.a2pgn","Final",8));
trn.insertGame(Game("p2.a2pgn", "SF1", 8));
trn.insertGame(Game("p3.a2pgn", "SF2", 8));
trn.insertGame(Game("p4.a2pgn", "QF1", 8));
trn.insertGame(Game("p5.a2pgn", "QF2", 8));
trn.insertGame(Game("p6.a2pgn", "QF3", 8));
trn.insertGame(Game("p7.a2pgn", "QF4", 8));
trn.insertGame(Game("p8.a2pgn", "PQF1", 8));
trn.insertGame(Game("p9.a2pgn", "PQF2", 8));
trn.insertGame(Game("p10.a2pgn", "PQF3", 8));
trn.insertGame(Game("p11.a2pgn", "PQF4", 8));
trn.insertGame(Game("p12.a2pgn", "PQF5", 8));
trn.insertGame(Game("p13.a2pgn", "PQF6", 8));
trn.insertGame(Game("p14.a2pgn", "PQF7", 8));
trn.insertGame(Game("p15.a2pgn", "PQF8", 8));

std::cout << "----Post Order traversal of Binary Search Tree of All Games---" << endl;
trn.show();
}
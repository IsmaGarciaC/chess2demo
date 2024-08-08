#pragma once
#include <iostream>
#include "coordinates.h"
#include "piece.h"
#include "square.h"

using namespace std;

class Board {
private:
    int numRows, numColumns;
    Square *squares;

public:
    static const string BOARD_START_GAME;
    static const string LEFT_EDGE;
    static const string RIGHT_EDGE;
    static const string MID_EDGE;
    static const string LINE_H;
    static const string LINE_V;
    static const string TOP_LEFT_CORNER;
    static const string TOP_RIGHT_CORNER;
    static const string BOT_LEFT_CORNER;
    static const string BOT_RIGHT_CORNER;
    static const string TOP_EDGE;
    static const string BOT_EDGE;
    static const string EMPTY_BLACK_CELL;
    static const string OCCUPIED_BLACK_CELL;
    static const string WHITE_CELL;

    void setNumRows(int rws);
    void setNumColumns(int clmns);

    int getNumRows();
    int getNumColumns();

    Square *getSquares();

    Piece *pieceEn(char column, int row);
    Piece *pieceEn(Coordinates *position);

    Board();
    Board(int dim);
    Board(int dim, string array_char_position);

    ~Board();

    static string moverString(int numColumns, int numRows, char c1, int f1, char c2, int f2, string str_board);

    friend ostream& operator<<(ostream& os, Board& t);
};

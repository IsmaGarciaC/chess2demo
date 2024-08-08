#pragma once
#include <iostream>
#include "coordinates.h"
#include "piece.h"

using namespace std;

class Square {
    friend class Board;

private:
    Coordinates coordinates;
    string color;
    Piece *piece;

public:
    static const string NAME_BLACK;
    static const string NAME_WHITE;
    static const string NAME_NO_COLOR;

    void setCoordinatesColor(char column, int row);
    void setColor(string color);
    void setPiece(Piece *pp);
    Coordinates getCoordinates();
    char getColumn();
    int getRow();
    string getColor();
    Piece* getPiece();

    Square();
    Square(Coordinates crdns, string clr, Piece *pp);
    ~Square();
};

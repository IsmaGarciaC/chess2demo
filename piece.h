#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "coordinates.h"
using namespace std;

class Board; // Forward declaration of the Board class

class Piece
{
public:
    static const string NAME_BLACK;
    static const string NAME_WHITE;
    static const string NAME_NO_COLOR;
    string name; // Name of the piece
    Coordinates position; // Position of the piece
    int value; // Value of the piece
    string color; // Color of the piece
    Board *board; // Pointer to the board

    void move(Coordinates checkFinal); // Moving the piece to a new position
    
    virtual int possibleMoves(Coordinates **&arrayMoves) = 0; //Virtual function to get possible moves
    
    Coordinates getPosition() const; // Getter for position
    
    friend ostream &operator<<(ostream &os, const Piece &p);
    
    Piece(string name, Coordinates position, string color, Board *board); // Constructor
    
    virtual ~Piece(); //Destructor
};

class Knight : public Piece
{
public:
    Knight(string name, Coordinates position, string color, Board *board); //Constructor
    int possibleMoves(Coordinates **&arrayMoves) override; //Overriding the function
};
class Pawn : public Piece
{
public:
    Pawn(string name, Coordinates position, string color, Board *board); // Constructor
    int possibleMoves(Coordinates **&arrayMoves) override; // Override the pure virtual function
    ~Pawn();
};
#endif

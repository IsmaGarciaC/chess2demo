#include "piece.h" // Include the piece header file
#include "board.h"
#include <iostream> 

const string Piece::NAME_BLACK = "black"; 
const string Piece::NAME_WHITE = "white"; 
const string Piece::NAME_NO_COLOR = "*"; 

Piece::Piece(string name, Coordinates position, string color, Board *board)
    : name(name), position(position), color(color), board(board), value(0) {} // Constructor initializing variables

Piece::~Piece() {} // Destructor

void Piece::move(Coordinates finalPosition) {
    position = finalPosition; // Moving the piece to the final position
}

Coordinates Piece::getPosition() const {
    return position; // Returning the current position of the piece
}

ostream &operator<<(ostream &os, const Piece &p) {
    os << p.name << " at " << p.position << " (" << p.color << ")"; // Output format
    return os; // Returning the output
}

Knight::Knight(string name, Coordinates position, string color, Board *board)
    : Piece(name, position, color, board) {
    value = 3; // Setting the value of the knight
}

int Knight::possibleMoves(Coordinates **&arrayMoves) {
    // Knight moves: 8 possible moves
    static const int moveOffsets[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    arrayMoves = new Coordinates *[8]; // 8 possible moves
    int count = 0;

    for (int i = 0; i < 8; ++i) {
        char newCol = position.getColumn() + moveOffsets[i][0]; // Calculate the new column
        int newRow = position.getRow() + moveOffsets[i][1]; // Calculate the new row

        cout << "Checking move: newCol = " << newCol << ", newRow = " << newRow << std::endl;

        if (newCol >= 'a' && newCol <= 'h' && newRow >= 1 && newRow <= 8) {
            Coordinates *newMove = new Coordinates(newCol, newRow); // Creating a new Coordinates object
            Piece *targetPiece = board->pieceEn(newMove); // Get the piece on the target square

            if (targetPiece == nullptr) {
                arrayMoves[count++] = newMove; // Add the move if the square is empty
            } else {
                cout << "Square " << *newMove << " is occupied." << endl;
                delete newMove; // Avoid memory leak
            }
        }
    }

    return count; // Returning the valid moves
}
Pawn::Pawn(string name, Coordinates position, string color, Board *board)
    : Piece(name, position, color, board) {
    value = 1; // Setting the value of the pawn
}
int Pawn::possibleMoves(Coordinates **&arrayMoves) {
    // Pawn moves: Only forward moves for now
    arrayMoves = new Coordinates *[2]; // Maximum 2 possible moves (1 step and 2 steps forward)
    int count = 0;
    
    int direction = (color == Piece::NAME_WHITE) ? 1 : -1; // White pawns move up, black pawns move down

    // One step forward
    char newCol = position.getColumn();
    int newRow = position.getRow() + direction;

    if (newRow >= 1 && newRow <= 8 && board->pieceEn(newCol, newRow) == nullptr) {
        arrayMoves[count++] = new Coordinates(newCol, newRow);
    }

    // Two steps forward (only if the pawn is in its initial position)
    if ((color == Piece::NAME_WHITE && position.getRow() == 2) || (color == Piece::NAME_BLACK && position.getRow() == 7)) {
        newRow = position.getRow() + 2 * direction;
        if (board->pieceEn(newCol, newRow) == nullptr) {
            arrayMoves[count++] = new Coordinates(newCol, newRow);
        }
    }

    return count; // Returning the valid moves
}

Pawn::~Pawn() {
    // Destructor logic if needed
}
#include "board.h"
#include "piece.h"

const string Board::BOARD_START_GAME = "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr";
const string Board::LEFT_EDGE = "\U00002523";
const string Board::RIGHT_EDGE = "\U0000252B";
const string Board::MID_EDGE = "\U0000254B";
const string Board::LINE_H = "\U00002501";
const string Board::LINE_V = "\U00002503";
const string Board::TOP_LEFT_CORNER = "\U0000250F";
const string Board::TOP_RIGHT_CORNER = "\U00002513";
const string Board::BOT_LEFT_CORNER = "\U00002517";
const string Board::BOT_RIGHT_CORNER = "\U0000251B";
const string Board::TOP_EDGE = "\U00002533";
const string Board::BOT_EDGE = "\U0000253B";
const string Board::EMPTY_BLACK_CELL = "\U00002592";
const string Board::OCCUPIED_BLACK_CELL = "\U00002591";
const string Board::WHITE_CELL = " ";

Board::Board() : numRows(8), numColumns(8) {
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numColumns; ++c) {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1); // Set coordinates and color of each square
        }
    }
}

Board::Board(int dim) : numRows(dim), numColumns(dim) {
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numColumns; ++c) {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1); // Set coordinates and color of each square
        }
    }
}

Board::Board(int dim, string array_char_position) : numRows(dim), numColumns(dim) {
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numColumns; ++c) {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1); // Set coordinates and color of each square
            char pieceChar = array_char_position[r * numColumns + c];        // Get the piece character from the array
            if (pieceChar != '-') {
                string pieceColor = isupper(pieceChar) ? Piece::NAME_WHITE : Piece::NAME_BLACK; // Determine the color of the piece
                Piece *newPiece = nullptr;                                                      // Pointer to the new piece
                switch (tolower(pieceChar)) {
                case 'p':
                    newPiece = new Pawn("Pawn", squares[r * numColumns + c].getCoordinates(), pieceColor, this);
                    break;
                case 'n':
                    newPiece = new Knight("Knight", squares[r * numColumns + c].getCoordinates(), pieceColor, this);
                    break;
                    // Add other pieces (e.g., rook, bishop, queen, king) as needed
                }
                if (newPiece) {
                    squares[r * numColumns + c].setPiece(newPiece); // Set the piece on the square
                }
            }
        }
    }
}

Board::~Board() {
    delete[] squares;
}

void Board::setNumRows(int rws) {
    numRows = rws; // Set the number of rows
}

void Board::setNumColumns(int clmns) {
    numColumns = clmns; // Set the number of columns
}

int Board::getNumRows() {
    return numRows;
}

int Board::getNumColumns() {
    return numColumns;
}

Square *Board::getSquares() {
    return squares;
}

Piece *Board::pieceEn(char column, int row) {
    return squares[(row - 1) * numColumns + (column - 'a')].getPiece(); // Return the piece at the specified column and row
}

Piece *Board::pieceEn(Coordinates *position) {
    return squares[(position->getRow() - 1) * numColumns + (position->getColumn() - 'a')].getPiece(); // Return the piece at the specified coordinates
}

string Board::moverString(int numColumns, int numRows, char c1, int f1, char c2, int f2, string str_board) {
    // Implement the logic to update the board string based on the move
    return str_board; // Placeholder return
}

ostream& operator<<(ostream& os,  Board& t)
{
   int numCols = t.getNumColumns();
   int numRows = t.getNumRows();
   Square *checks = t.getSquares();

   cout << endl;
   for (int j=0; j < numCols; j++)
   {
       if (j==0 )
           os << Board::TOP_LEFT_CORNER;
       if (j < numCols - 1)
           os << Board::LINE_H +Board::LINE_H +Board::LINE_H + Board::TOP_EDGE;
       else
           os << Board::LINE_H +Board::LINE_H +Board::LINE_H + Board::TOP_RIGHT_CORNER;
   }
   for (int i = numRows-1; i>=0; i--)
   {
       os << endl << Board::LINE_V;
       for (int j=0; j < numCols ; j++)
       {
           Piece *crrnt_p = t.pieceEn( Coordinates::indexToColumn(j), i );
           if (crrnt_p == NULL)
           {
               if ((i+j)%2 != 0 )
                   os << Board::WHITE_CELL +Board::WHITE_CELL +Board::WHITE_CELL;
               else
                   os << Board::EMPTY_BLACK_CELL +Board::EMPTY_BLACK_CELL+Board::EMPTY_BLACK_CELL;
          
           }
           else
           {
                if ((i+j)%2 != 0 )
                {
                   os << Board::WHITE_CELL;
                   os << *crrnt_p;
                   os << Board::WHITE_CELL;
                }
                else
                {
                    os << Board::OCCUPIED_BLACK_CELL;
                    os << *crrnt_p;
                    os << Board::OCCUPIED_BLACK_CELL;
                }

           }
           os << Board::LINE_V;
       }
       os  << " " << i+1 << endl ;
       for (int j=0; j < numCols; j++)
       {
           if (i== 0)
           {
               if (j==0 )
                   os << Board::BOT_LEFT_CORNER + Board::LINE_H + Board::LINE_H  + Board::LINE_H  + Board::BOT_EDGE;
               else if ( j == numCols -1)
                   os << Board::LINE_H + Board::LINE_H + Board::LINE_H +  Board::BOT_RIGHT_CORNER;
               else
                   os << Board::LINE_H + Board::LINE_H + Board::LINE_H +  Board::BOT_EDGE;
           }
           else
           {
               if (j==0 )
                   os << Board::LEFT_EDGE + Board::LINE_H + Board::LINE_H  + Board::LINE_H  + Board::MID_EDGE;
               else if ( j == numCols -1 )
                   os << Board::LINE_H + Board::LINE_H + Board::LINE_H +  Board::RIGHT_EDGE;
               else
                   os << Board::LINE_H + Board::LINE_H + Board::LINE_H +  Board::MID_EDGE;
           }
       }       
   }


   os << endl;
   os << " ";
   for (int j=0; j < numCols; j++)
   {
       os << " " << Coordinates::indexToColumn(j) << "  ";
   }
   os  << endl ;

   return os;
}


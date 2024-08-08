#include "coordinates.h"

Coordinates::Coordinates() : column('a'), row(1) {}

Coordinates::Coordinates(char column, int row) : column(column), row(row) {}

Coordinates::Coordinates(const Coordinates &crdns) : column(crdns.column), row(crdns.row) {}

// Convert a column index to a character (e.g., 0 -> 'a', 1 -> 'b')
char Coordinates::indexToColumn(int idc) {
    if (idc < 0 || idc > 7) {
        throw std::out_of_range("Index is out of the valid range.");
    }
    return 'a' + idc;
}

int Coordinates::columnToIndex(char column) {
    if (column < 'a' || column > 'h') {
        throw std::out_of_range("Column is out of the valid range.");
    }
    return column - 'a';
}

char Coordinates::getColumn() const {
    return column;
}

int Coordinates::getRow() const {
    return row;
}

void Coordinates::setColumn(char clmn) {
    column = clmn;
}

void Coordinates::setRow(int row) {
    this->row = row;
}

ostream &operator<<(ostream &os, const Coordinates &crdnd) {
    os << "[" << crdnd.column << ", " << crdnd.row << "]";
    return os;
}

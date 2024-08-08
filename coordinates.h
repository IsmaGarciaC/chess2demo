#pragma once
#include <iostream>
using namespace std;

class Coordinates {
public:
    Coordinates();
    Coordinates(char column, int row);
    Coordinates(const Coordinates &crdns);
    
    // Methods for column indexing
    static int columnToIndex(char column); // Convert column character to index
    static char indexToColumn(int idc);    // Convert index to column character
    
    // Getters
    char getColumn() const;
    int getRow() const;

    // Setters
    void setColumn(char clmn);
    void setRow(int row);

    friend ostream &operator<<(ostream &os, const Coordinates &crdnd);

private:
    char column;
    int row;
};

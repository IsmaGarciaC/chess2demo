#pragma once
#include <iostream>
#include "board.h"
#include "unorderedLinkedList.h"

class Game {
public:
    // Setters
    void setKey(int k);
    void setName(std::string nmbr);
    void setBoards(unorderedLinkedList<Board> brds);

    // Getters
    int getKey() const;
    std::string getName() const;
    unorderedLinkedList<Board> getBoards() const;  // Ensure this is a member function

    // Constructors
    Game();
    Game(std::string filename, std::string name, int dim);

    // Overloaded operators
    friend bool operator>=(const Game &p1, const Game &p2);
    friend bool operator<(const Game &p1, const Game &p2);
    friend std::ostream& operator<<(std::ostream& os, const Game& p);

private:
    int key;
    std::string name;
    unorderedLinkedList<Board> boards;
};

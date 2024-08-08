#include "game.h"
#include <fstream>

// Member function definitions

void Game::setKey(int k) { key = k; }
void Game::setName(std::string nmbr) { name = nmbr; }
void Game::setBoards(unorderedLinkedList<Board> brds) { boards = brds; }

int Game::getKey() const { return key; }
std::string Game::getName() const { return name; }

// Correctly define getBoards() as a member function
unorderedLinkedList<Board> Game::getBoards() const { 
    return boards; 
}

Game::Game() : key(0), name(""), boards() {}

Game::Game(std::string filename, std::string name, int dim) : name(name) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::cout << "Successfully opened file: " << filename << std::endl;

    std::string board_str = Board::BOARD_START_GAME;
    boards.insertLast(Board(dim, board_str));

    std::string line;
    while (getline(file, line)) {
        if (line.length() < 4) continue;
        char c1 = line[0];
        int f1 = line[1] - '0';
        char c2 = line[2];
        int f2 = line[3] - '0';
        board_str = Board::moverString(dim, dim, c1, f1, c2, f2, board_str);
        boards.insertLast(Board(dim, board_str));
    }

    file.close();
}

bool operator>=(const Game &p1, const Game &p2) {
    return p1.key >= p2.key;
}

bool operator<(const Game &p1, const Game &p2) {
    return p1.key < p2.key;
}

std::ostream& operator<<(std::ostream& os, const Game& p) {
    os << "Game Name: " << p.name << " Key: " << p.key << std::endl;
    auto boards = p.getBoards();
    for (auto it = boards.begin(); it != boards.end(); ++it) {
        os << *it << std::endl;
    }
    return os;
}

#pragma once
#include <iostream>
#include "game.h"

class BSNode {
public:
    Game data;
    BSNode* left;
    BSNode* right;

    BSNode(Game d) : data(d), left(nullptr), right(nullptr) {}
};

class BSearchTreeType {
public:
    BSNode* head;

    BSearchTreeType() : head(nullptr) {}

    void insert(Game game) {
        head = insertNode(head, game);
    }

    BSNode* insertNode(BSNode* node, Game game) {
        if (node == nullptr) {
            return new BSNode(game);
        }
        if (game.getKey() < node->data.getKey()) {
            node->left = insertNode(node->left, game);
        } else {
            node->right = insertNode(node->right, game);
        }
        return node;
    }

    void postOrder() {
        postOrderTraversal(head);
    }

    void postOrderTraversal(BSNode* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout << node->data << std::endl;
    }
};

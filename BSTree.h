//
// Created by arash on 12/1/15.
//

#ifndef DATASTRUCTURES_BSTREE_H
#define DATASTRUCTURES_BSTREE_H

#include <iostream>
#include <stddef.h>
#include "BTNode.h"

template<typename Value>
class BSTree {
private:
    BTNode<int, Value> *root;
    int nodeCounter;

    BTNode<int, Value> *insertHelper(BTNode<int, Value> *root, int key, Value value) {
        if (root == NULL) { return new BTNode<int, Value>(key, value); }
        if (key < this->root->getKey())
            root->setLeft(insertHelper(root->getLeft(), key, value));
        else
            root->setRight(insertHelper(root->getRight(), key, value));
        return root;
    }

    void printHelper(BTNode<int, Value> *root) {
        if (root == NULL) return;
        std::cout << "key :" << root->getKey() << " - value :" << root->getValue() << std::endl;
        printHelper(root->getLeft());
        printHelper(root->getLeft());
    }

public:
    BSTree() {
        this->root = NULL;
    }

    void insert(int key, Value value) {
        this->root = this->insertHelper(this->root, key, value);
        nodeCounter ++;
    }

    void print() {
        this->printHelper(this->root);
    }
};


#endif //DATASTRUCTURES_BSTREE_H

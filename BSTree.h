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

    BTNode<int, Value> *insertHelper(BTNode<int, Value> * _root, int _key, Value _value) {
        if (_root == NULL) { return new BTNode<int, Value>(_key, _value); }
        if (_key < this->root->getKey())
            _root->setLeft(insertHelper(_root->getLeft(), _key, _value));
        else
            _root->setRight(insertHelper(_root->getRight(), _key, _value));
        return _root;
    }

    void printHelper(BTNode<int, Value> *_root) {
        if (_root == NULL) return;
        std::cout << "key :" << _root->getKey() << " - value :" << _root->getValue() << std::endl;
        printHelper(_root->getLeft());
        printHelper(_root->getLeft());
    }

public:
    BSTree() {
        this->root = NULL;
    }

    void insert(int _key, Value _value) {
        this->root = this->insertHelper(this->root, _key, _value);
        nodeCounter ++;
    }

    void print() {
        this->printHelper(this->root);
    }
};


#endif //DATASTRUCTURES_BSTREE_H

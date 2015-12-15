//
// Created by arash on 12/1/15.
//

#ifndef DATASTRUCTURES_BTNODE_H
#define DATASTRUCTURES_BTNODE_H

//this is binary search tree node :)

#include <stddef.h>

template <typename Key,typename Value>
class BTNode {
private :
    Key key ;
    Value value;
    BTNode<Key,Value> * right;
    BTNode<Key,Value> * left;

public :
    BTNode(){}
    BTNode(Key _key , Value _value){
        this->key = _key;
        this->value = _value;
        this->right = NULL;
        this->left = NULL;
    }
    BTNode(Key _key, Value _value, BTNode<Key,Value> * _right , BTNode<Key,Value> * _left){
        this->key = _key;
        this->value = _value;
        this->right = _right;
        this->left = _left;
    }

    //getters and setters
    Key getKey(){
        return this->key;
    }
    void setKey(Key _key){
        this->key = _key;
    }

    Value getValue(){
        return this->value;
    }
    void setValue(Value _value){
        this->value = _value ;
    }

    BTNode<Key, Value> * getRight(){
        return this->right;
    };
    void setRight(BTNode<Key, Value> * _right){
        this->right = _right;
    }

    BTNode<Key, Value> * getLeft(){
        return this->left;
    };
    void setLeft(BTNode<Key, Value> * _left){
        this->left = _left;
    }
};


#endif //DATASTRUCTURES_BTNODE_H

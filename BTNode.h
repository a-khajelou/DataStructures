//
// Created by arash on 12/1/15.
//

#ifndef DATASTRUCTURES_BTNODE_H
#define DATASTRUCTURES_BTNODE_H

//this is binary search tree node :)

template <typename Key,typename Value>
class BTNode {
private :
    Key key ;
    Value value;
    BTNode<Key,Value> * right;
    BTNode<Key,Value> * left;

public :
    BTNode(){}
    BTNode(Key key , Value value){
        this->key = key;
        this->value = value;
        this->right = NULL;
        this->left = NULL;
    }
    BTNode(Key key, Value value, BTNode<Key,Value> * right , BTNode<Key,Value> * left){
        this->key = key;
        this->value = value;
        this->right = right;
        this->left = left;
    }

    //getters and setters
    Key getKey(){
        return this->key;
    }
    void setKey(Key key){
        this->key = key;
    }

    Value getValue(){
        return this->value;
    }
    void setValue(Value value){
        this->value = value ;
    }

    BTNode<Key, Value> * getRight(){
        return this->right;
    };
    void setRight(BTNode<Key, Value> * right){
        this->right = right;
    }

    BTNode<Key, Value> * getLeft(){
        return this->left;
    };
    void setLeft(BTNode<Key, Value> * left){
        this->left = left;
    }
};


#endif //DATASTRUCTURES_BTNODE_H

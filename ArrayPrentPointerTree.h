//
// Created by Arash Khajelou on 12/15/15.
//

#ifndef DATASTRUCTURES_ARRAYPRENTPOINTERTREE_H
#define DATASTRUCTURES_ARRAYPRENTPOINTERTREE_H


#include "LinkedList.h"
#include "PPTNode.h"

class ArrayPrentPointerTree {
private:
    LinkedList<PPTNode> *linkedList;
    int nodeCount;


public:
    ArrayPrentPointerTree() {
        this->nodeCount = 0;
        this->linkedList = new LinkedList<PPTNode>();
    }

    PPTNode *getItemById(int _id) {
        this->linkedList->moveToFirst();
        while (this->linkedList->hasMoreElements()) {
            PPTNode *tmpPPTNode = this->linkedList->getNext();
            if (tmpPPTNode->getId() == _id)
                return tmpPPTNode;
        }

        return NULL;
    }

    bool insert(PPTNode *_pptNode, int _parentId = -1) {
        if (_parentId != -1 and this->getItemById(_parentId) == NULL)
            return false;
        if (_pptNode->getId() != -1)
            return this->update(_pptNode);
        _pptNode->setId(this->linkedList->append(_pptNode));
        _pptNode->setParentId(_parentId);
        return true;
    }

    bool insert(PPTNode *_pptNode, PPTNode *_parent) {
        return this->insert(_pptNode, _parent->getId());
    }

    bool update(PPTNode *_pptNode) {
        if (_pptNode->getId() == -1) {
            //throw exception
            return false;
        }
        PPTNode *tmpPPTNode = this->getItemById(_pptNode->getId());
        if(tmpPPTNode == NULL)
            return false;
        tmpPPTNode->setName(_pptNode->getName());
        return true;
    }

    void print() {
        this->linkedList->moveToFirst();
        while (this->linkedList->hasMoreElements()) {
            std::cout << this->linkedList->getNext();
        }
    }

    //delete and other functions ...
};


#endif //DATASTRUCTURES_ARRAYPRENTPOINTERTREE_H

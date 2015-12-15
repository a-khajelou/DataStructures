//
// Created by Arash Khajelou on 12/15/15.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

#include <iostream>
#include "Link.h"

template<typename T>
class LinkedList {
private:
    Link<T> *start;
    Link<T> *end;
    Link<T> *current;
    int size;

public:
    LinkedList() {
        this->start = new Link<T>(NULL);
        this->end = new Link<T>(NULL);

        this->start->setNext(this->end);
        this->start->setPrev(NULL);

        this->end->setNext(NULL);
        this->end->setPrev(this->start);

        this->current = this->start;
    }

    LinkedList(T *inputList, int size) {
        this->start = new Link<T>(NULL);
        this->end = new Link<T>(NULL);

        this->start->setNext(this->end);
        this->start->setPrev(NULL);

        this->end->setNext(NULL);
        this->end->setPrev(this->start);

        this->current = this->start;

        for(int i=0; i<size; i++){
            this->append(inputList[i]);
        }
    }

    void append(T _newItem) {
        Link<T> *newItem = new Link<T>(_newItem, this->end, this->end->getPrev());
        this->end->getPrev()->setNext(newItem);
        this->end->setPrev(newItem);
        this->size++;
    }

    void insert(T _newItem, int index) {
        Link<T> *tmp = this->start;
        for (int indexCounter = 0; indexCounter < index; indexCounter++) {
            if (tmp->getNext()->getNext() == NULL) {
                std::cout << "\nIndex out of range\n";
                return;
            }
            tmp = tmp->getNext();
        }

        Link<T> *newItem = new Link<T>(_newItem, tmp->getNext(), tmp);
        tmp->setNext(newItem);
        tmp->getNext()->setPrev(newItem);
        this->size++;
    }

    bool moveToNext() {
        if (this->hasMoreElements()) {
            current = current->getNext();
            return true;
        }
        return false;
    }

    void moveToFirst() {
        this->current = this->start;
    }

    bool hasMoreElements() {
        return current->getNext()->getNext() != NULL;
    }

    T getNext() {
        if (!this->moveToNext()) {
            std::cout << "\nthere is no more elements\n";
            return NULL;
        }
        return current->getElement();
    }

    T get(int index) {
        Link<T> *tmp = this->start;
        for (int indexCounter = 0; indexCounter < index; indexCounter++) {
            if (tmp->getNext()->getNext() == NULL) {
                std::cout << "\nIndex out of range\n";
                return NULL;
            }
            tmp = tmp->getNext();
        }
        return tmp->getNext()->getElement();
    }

};


#endif //DATASTRUCTURES_LINKEDLIST_H

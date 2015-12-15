//
// Created by Arash Khajelou on 12/15/15.
//

#ifndef DATASTRUCTURES_LINKEDMAP_H
#define DATASTRUCTURES_LINKEDMAP_H

#include <iostream>
#include "Map.h"

template<typename Key, typename Value>
class LinkedMap {
    private:
        Map<Key,Value> *start;
        Map<Key,Value> *end;
        Map<Key,Value> *current;
        int size;

    public:
        LinkedMap() {
            this->start = new Map<Key,Value>(NULL,NULL);
            this->end = new Map<Key,Value>(NULL,NULL);

            this->start->setNext(this->end);
            this->start->setPrev(NULL);

            this->end->setNext(NULL);
            this->end->setPrev(this->start);

            this->current = this->start;
        }

        LinkedMap(Key *keysList,Value *valuesList, int size) {
            this->start = new Map<Key,Value>(NULL,NULL);
            this->end = new Map<Key,Value>(NULL,NULL);

            this->start->setNext(this->end);
            this->start->setPrev(NULL);

            this->end->setNext(NULL);
            this->end->setPrev(this->start);

            this->current = this->start;

            for(int i=0; i<size; i++){
                this->put(keysList[i], valuesList[i]);
            }
        }

        void put(Key _key, Value _value) {
            Map<Key,Value> *newItem = new Map<Key,Value>(_key,_value, this->end, this->end->getPrev());
            this->end->getPrev()->setNext(newItem);
            this->end->setPrev(newItem);
            this->size++;
        }

        void insert(Key _key,Value _value, int index) {
            Map<Key,Value> *tmp = this->start;
            for (int indexCounter = 0; indexCounter < index; indexCounter++) {
                if (tmp->getNext()->getNext() == NULL) {
                    std::cout << "\nIndex out of range\n";
                    return;
                }
                tmp = tmp->getNext();
            }

            Map<Key,Value> *newItem = new Map<Key,Value>(_key,_value, tmp->getNext(), tmp);
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

        Value getNext() {
            if (!this->moveToNext()) {
                std::cout << "\nthere is no more elements\n";
                return NULL;
            }
            return current->getValue();
        }

        Map<Key, Value> * getByIndex(int index) {
            Map<Key,Value> *tmp = this->start;
            for (int indexCounter = 0; indexCounter < index; indexCounter++) {
                if (tmp->getNext()->getNext() == NULL) {
                    std::cout << "\nIndex out of range\n";
                    return NULL;
                }
                tmp = tmp->getNext();
            }
            return tmp->getNext();
        }
};


#endif //DATASTRUCTURES_LINKEDMAP_H

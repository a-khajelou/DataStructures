//
// Created by Arash Khajelou on 12/15/15.
//

#ifndef DATASTRUCTURES_MAP_H
#define DATASTRUCTURES_MAP_H

#include <stddef.h>

template<typename Key, typename Value>
class Map {
private:
    Key key;
    Value value;
    Map *next;
    Map *prev;

public:

    Map(Key _key, Value _value){
        this->key = _key;
        this->value = _value;
        this->next = NULL;
        this->prev = NULL;
    }

    Map(Key _key,Value _value, Map* _next , Map* _prev){
        this->key = _key;
        this->value = _value;
        this->next = _next;
        this->prev = _prev;
    }

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
        this->value = _value;
    }

    Map * getNext(){
        return this->next;
    }

    void setNext(Map * _next){
        this->next = _next;
    }

    Map * getPrev(){
        return this->prev;
    }

    void setPrev(Map * _prev){
        this->prev = _prev;
    }

};


#endif //DATASTRUCTURES_MAP_H

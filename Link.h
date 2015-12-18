//
// Created by Arash Khajelou on 12/15/15.
//

#ifndef DATASTRUCTURES_LINK_H
#define DATASTRUCTURES_LINK_H

#include <stddef.h>

template<typename T>
class Link {
private:
    T *element;
    Link *next;
    Link *prev;

public:

    Link(T *_element) {
        this->element = _element;
        this->next = NULL;
        this->prev = NULL;
    }

    Link(T *_element, Link *_next, Link *_prev) {
        this->element = _element;
        this->next = _next;
        this->prev = _prev;
    }

    T *getElement() {
        return this->element;
    }

    void setElement(T *_element) {
        this->element = _element;
    }

    Link *getNext() {
        return this->next;
    }

    void setNext(Link *_next) {
        this->next = _next;
    }

    Link *getPrev() {
        return this->prev;
    }

    void setPrev(Link *_prev) {
        this->prev = _prev;
    }

};


#endif //DATASTRUCTURES_LINK_H

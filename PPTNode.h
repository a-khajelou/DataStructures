//
// Created by Arash Khajelou on 12/18/15.
//

#ifndef DATASTRUCTURES_PPTNODE_H
#define DATASTRUCTURES_PPTNODE_H

#include <iostream>

class PPTNode {
private:
    int id ;
    char* name ;
    //if null -> the node is root , if int -> there is parent with id : parentId :)
    int parentId;

public:
    PPTNode(){
        this->id = -1;
        this->parentId = -1;
        this->name = "" ;
    }

    PPTNode(char* name){
        this->name = name;
        this->id = -1;
        this->parentId = -1;
    }

    int getId(){
        return this->id;
    }

    void setId(int _id){
        this->id = _id;
    }

    int getParentId(){
        return this->parentId;
    }

    void setParentId(int _parentId){
        this->parentId = _parentId;
    }

    char* getName(){
        return this->name;
    }

    void setName(char* _name){
        this->name = _name;
    }

    friend std::ostream & operator << (std::ostream & out , const PPTNode * _pptNode){
        out<<"ppnode id : " << _pptNode->id <<std::endl;
        out<<"ppnode name : " << _pptNode->name<<std::endl;
        out<<"ppnode parent id : " << _pptNode->parentId<<std::endl;

        return out;
    }
};


#endif //DATASTRUCTURES_PPTNODE_H

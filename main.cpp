#include <iostream>
#include "BTNode.h"
#include "BSTree.h"

using namespace std;

int main() {
    BSTree<string>* bsTree = new BSTree<string>;

    for(int i=0; i<10; i++){
        int key = 0;
        cout<<"please enter key for node "<<i<<" : ";
        cin>>key;
        string value;
        cout<<"please enter value for node "<<i<<" : ";
        cin>>value;

        bsTree->insert(key,value);
    }

    cout<<endl;
    bsTree->print();

    return 0;
}
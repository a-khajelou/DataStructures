#include <iostream>
#include "LinkedList.h"
#include "ArrayPrentPointerTree.h"

using namespace std;

int main() {
    ArrayPrentPointerTree arrayPrentPointerTree;
    PPTNode * pptNode = new PPTNode("Arash");
    PPTNode * pptNode1 = new PPTNode("Arman");

    arrayPrentPointerTree.insert(pptNode);
    arrayPrentPointerTree.insert(pptNode1);

    PPTNode * pptNode2 = new PPTNode("Saeed");
    pptNode2->setId(0);
    arrayPrentPointerTree.update(pptNode2);

    arrayPrentPointerTree.print();

    return 0;
}
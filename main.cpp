#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    LinkedList<int> linkedList(a, 10);

    cout<<endl;
    linkedList.moveToFirst();
    cout<<linkedList.get(10);

    return 0;
}
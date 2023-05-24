#include <iostream>
#include "LinkedList.h"

using namespace std;

#include "Functions.h"


int main() {
    LinkedList<string> list;

    printListStatus(list);
    addElements(list);
    printListStatus(list);
    printList(list);
    searchElement(list);
    removeElement(list);
    printList(list);
    list.clear();
    printListStatus(list);

    return 0;
}

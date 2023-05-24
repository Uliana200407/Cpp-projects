
#include <iostream>
using namespace std;
#include "Functions.h"
#include "LinkedList.h"
#include <limits>


void printListStatus(const LinkedList<string>& list) {
    cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
}

void addElements(LinkedList<string>& list) {
    int numElements;
    cout << "Enter the number of elements to add: ";

    while (!(cin >> numElements)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter " << numElements << " elements:" << endl;
    for (int i = 0; i < numElements; i++) {
        string value;
        cin >> value;
        list.insertAtBeginning(value);
    }
}

void printList(const LinkedList<string>& list) {
    cout << "List elements: ";
    for (Iterator<string> it = list.begin(); !it.isEnd(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void searchElement(const LinkedList<string>& list) {
    string searchValue;
    cout << "Enter a value to search in the list: ";
    cin >> searchValue;

    int position = list.find(searchValue);
    if (position != -1) {
        cout << "Element " << searchValue << " found at position: " << position << endl;
    } else {
        cout << "Element " << searchValue << " not found" << endl;
    }
}

void removeElement(LinkedList<string>& list) {
    int removePosition;
    cout << "Enter a position to remove an element from: ";

    while (!(cin >> removePosition)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    list.removeAt(removePosition);
}
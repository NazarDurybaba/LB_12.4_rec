#include <iostream>

// Structure for a node of a singly linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Class for a circular singly linked list
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Adding an element to the list
    void addElement(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Checking if all elements of list L1 are in list L2
    bool allElementsInList(CircularLinkedList& otherList) {
        if (!head) // If list L1 is empty, return true
            return true;

        Node* tempL1 = head;
        do {
            bool found = false;
            Node* tempL2 = otherList.head;
            if (!tempL2) // If list L2 is empty, return false
                return false;
            do {
                if (tempL1->data == tempL2->data) {
                    found = true;
                    break;
                }
                tempL2 = tempL2->next;
            } while (tempL2 != otherList.head);
            if (!found)
                return false;
            tempL1 = tempL1->next;
        } while (tempL1 != head);

        return true; // All elements of L1 found in L2
    }

    // Displaying the list
    void display() {
        if (!head) {
            std::cout << "The list is empty\n";
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

// Main function
int main() {
    CircularLinkedList L1, L2;

    // Adding elements to lists L1 and L2
    L1.addElement(1);
    L1.addElement(2);
    L1.addElement(3);

    L2.addElement(3);
    L2.addElement(2);
    L2.addElement(1);

    std::cout << "List L1: ";
    L1.display();
    std::cout << "List L2: ";
    L2.display();

    // Checking if all elements of list L1 are in list L2
    if (L1.allElementsInList(L2))
        std::cout << "All elements of list L1 are in list L2.\n";
    else
        std::cout << "Not all elements of list L1 are in list L2.\n";

    return 0;
}

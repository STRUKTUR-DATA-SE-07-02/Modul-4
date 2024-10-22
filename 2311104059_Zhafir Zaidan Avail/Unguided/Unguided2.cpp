#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}
void insertFront(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}
void insertBack(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty, no node to delete.\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node with value " << value << " deleted from the list.\n";
        return;
    }
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Node with value " << value << " not found in the list.\n";
        return;
    }
    previous->next = current->next;
    delete current;
    cout << "Node with value " << value << " deleted from the list.\n";
}
void printList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    insertFront(head, 10);
    insertFront(head, 5);
    insertBack(head, 20);

    cout << "Linked List before deletion: ";
    printList(head);
    deleteNode(head, 10);
    cout << "Linked List after deletion: ";
    printList(head);
    return 0;
}

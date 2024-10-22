#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void addFront(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void addBack(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) return;

    previous->next = current->next;
    delete current;
}

void printList(Node* head) {
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
    addFront(head, 10);
    addBack(head, 20);
    addFront(head, 5);

    cout << "Linked List sebelum penghapusan: ";
    printList(head);

    deleteNode(head, 10);

    cout << "Linked List setelah penghapusan node dengan nilai 10: ";
    printList(head);

    while (head != nullptr) {
        deleteNode(head, head->data);
    }

    return 0;
}
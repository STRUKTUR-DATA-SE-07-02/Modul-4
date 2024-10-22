#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the front
void insertFront(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the back
void insertBack(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a given value
void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = nullptr;

    // If head node itself holds the value to be deleted
    if (temp != nullptr && temp->data == value) {
        *head = temp->next; // Change head
        delete temp; // Free old head
        return;
    }

    // Search for the value to be deleted
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not present in the list
    if (temp == nullptr) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    delete temp; // Free memory
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
        if (temp != nullptr) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertFront(&head, 10);
    insertBack(&head, 20);
    insertFront(&head, 5);
    
    cout << "Linked List before deletion: ";
    printList(head);

    deleteNode(&head, 10);
    
    cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}
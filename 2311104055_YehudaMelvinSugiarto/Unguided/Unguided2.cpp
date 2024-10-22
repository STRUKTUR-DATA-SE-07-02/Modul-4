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

void insertAtFront(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);

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

void printList(Node* head) {
    if (head == nullptr) {
        cout << "Linked List kosong." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Linked List kosong, tidak bisa menghapus." << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node dengan nilai " << value << " berhasil dihapus." << endl;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Node dengan nilai " << value << " berhasil dihapus." << endl;
}

int main() {
    Node* head = nullptr;

    insertAtFront(head, 10);
    insertAtEnd(head, 20);
    insertAtFront(head, 5);

    cout << "Isi Linked List sebelum penghapusan: ";
    printList(head);

    deleteNode(head, 10);

    cout << "Isi Linked List setelah penghapusan: ";
    printList(head);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}
// Fungsi untuk menambahkan node di depan (awal) linked list
void insertAtFront(Node* &head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}
// Fungsi untuk menambahkan node di belakang linked list
void insertAtEnd(Node* &head, int value) {
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
// Fungsi untuk mencetak seluruh isi linked list
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List kosong!" << endl;
    } else {
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
}
int main() {
    Node* head = nullptr;
    // Operasi berdasarkan contoh
    insertAtFront(head, 10);
    insertAtEnd(head, 20);
    insertAtFront(head, 5);
    // Cetak isi linked list
    cout << "Isi linked list: ";
    printList(head);
    return 0;
}

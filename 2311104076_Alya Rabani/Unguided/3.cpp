#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node di depan
void insertFront(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Fungsi untuk menambah node di belakang
void insertBack(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
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

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node* head, int key) {
    Node* current = head; 
    while (current != nullptr) {  
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Fungsi untuk menghitung panjang linked list
int countLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi untuk mencetak isi linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data;
        if (node->next != nullptr) {
            cout << "-> ";
        }
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Tambah beberapa node
    insertFront(&head, 10);
    insertBack(&head, 20);
    insertFront(&head, 5);

    // Cetak linked list
    cout << "Isi linked list: ";
    printList(head);

    // Cari node dengan nilai tertentu
    int searchVal = 20;
    if (searchNode(head, searchVal)) {
        cout << "Node dengan nilai " << searchVal << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << searchVal << " tidak ditemukan." << endl;
    }

    // Hitung panjang linked list
    int length = countLength(head);
    cout << "Panjang linked list: " << length << endl;

    return 0;
}
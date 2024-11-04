#include <iostream>
using namespace std;

// Struktur node dari linked list
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

    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true; // Node ditemukan
        }
        current = current->next;
    }
    return false; // Node tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi untuk mencetak seluruh isi linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Inisialisasi linked list kosong

    // Contoh input
    insertFront(&head, 10); // Tambah node di depan (10)
    insertBack(&head, 20);  // Tambah node di belakang (20)
    insertFront(&head, 5);  // Tambah node di depan (5)

    // Cari node dengan nilai 20
    int searchValue = 20;
    if (searchNode(head, searchValue)) {
        cout << "Node dengan nilai " << searchValue << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << endl;
    }

    // Hitung panjang linked list
    int length = countNodes(head);
    cout << "Panjang linked list: " << length << endl;

    return 0;
}

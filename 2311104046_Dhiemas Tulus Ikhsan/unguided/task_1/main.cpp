#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    int data;
    Node* next;
};

// Deklarasi pointer untuk head dan tail
Node* head = nullptr;
Node* tail = nullptr;

// Fungsi untuk menambah node di depan
void insertDepan(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        // Jika list kosong, node pertama menjadi head dan tail
        head = tail = baru;
    } else {
        // Jika list tidak kosong, node baru menjadi head
        baru->next = head;
        head = baru;
    }
}

// Fungsi untuk menambah node di belakang
void insertBelakang(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        // Jika list kosong, node pertama menjadi head dan tail
        head = tail = baru;
    } else {
        // Jika list tidak kosong, node baru ditambahkan di belakang tail
        tail->next = baru;
        tail = baru;
    }
}

// Fungsi untuk mencetak seluruh isi linked list
void cetakList() {
    if (head == nullptr) {
        cout << "Linked list kosong.\n";
    } else {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
}

// Main function
int main() {
    // Contoh penggunaan fungsi
    insertDepan(10);    // Tambah node di depan (nilai: 10)
    insertBelakang(20); // Tambah node di belakang (nilai: 20)
    insertDepan(5);     // Tambah node di depan (nilai: 5)

    // Cetak isi linked list
    cetakList();

    return 0;
}

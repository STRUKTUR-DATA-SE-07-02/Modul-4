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
        head = tail = baru;
    } else {
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
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Fungsi untuk mencari node dengan nilai tertentu
bool cariNode(int nilai) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == nilai) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Fungsi untuk menghitung panjang linked list
int hitungPanjang() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Main function
int main() {
    // Contoh penggunaan fungsi
    insertDepan(10);    // Tambah node di depan (nilai: 10)
    insertBelakang(20); // Tambah node di belakang (nilai: 20)
    insertDepan(5);     // Tambah node di depan (nilai: 5)

    // Cari node dengan nilai 20
    int nilaiCari = 20;
    if (cariNode(nilaiCari)) {
        cout << "Node dengan nilai " << nilaiCari << " ditemukan.\n";
    } else {
        cout << "Node dengan nilai " << nilaiCari << " tidak ditemukan.\n";
    }

    // Hitung panjang linked list
    cout << "Panjang linked list: " << hitungPanjang() << endl;

    return 0;
}

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

// Fungsi untuk menghapus node dengan nilai tertentu
void hapusNode(int nilai) {
    if (head == nullptr) {
        return;
    }

    // Jika node yang dihapus adalah head
    if (head->data == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    // Mencari node yang akan dihapus
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && current->data != nilai) {
        prev = current;
        current = current->next;
    }

    // Jika node ditemukan
    if (current != nullptr) {
        prev->next = current->next;
        // Jika node yang dihapus adalah tail, perbarui tail
        if (current == tail) {
            tail = prev;
        }
        delete current;
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
                cout << "->";
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

    // Hapus node dengan nilai 10
    hapusNode(10);

    // Cetak isi linked list setelah penghapusan
    cetakList();

    return 0;
}

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

// Fungsi untuk menghapus node dengan nilai tertentu
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = nullptr;

    // Jika node head yang akan dihapus
    if (temp != nullptr && temp->data == key) {
        *head = temp->next; // Ubah head
        delete temp; // Hapus node
        return;
    }

    // Cari node yang akan dihapus, simpan node sebelumnya
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Jika node dengan nilai tersebut tidak ditemukan
    if (temp == nullptr) {
        cout << "Nilai " << key << " tidak ditemukan dalam linked list.\n";
        return;
    }

    // Hapus node
    prev->next = temp->next;
    delete temp;
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

    // Cetak linked list sebelum penghapusan
    cout << "Linked List sebelum penghapusan: ";
    printList(head); // Output: 5 -> 10 -> 20

    // Hapus node dengan nilai 10
    deleteNode(&head, 10);

    // Cetak linked list setelah penghapusan
    cout << "Linked List setelah penghapusan: ";
    printList(head); // Output: 5 -> 20

    return 0;
}

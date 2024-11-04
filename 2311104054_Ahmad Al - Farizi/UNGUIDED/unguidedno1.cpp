#include <iostream>
using namespace std;

// Struktur node dari linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node di depan
void insertFront(Node** head, int newData) {
    // Buat node baru
    Node* newNode = new Node();
    newNode->data = newData;

    // Hubungkan node baru ke head lama
    newNode->next = *head;

    // Jadikan node baru sebagai head
    *head = newNode;
}

// Fungsi untuk menambah node di belakang
void insertBack(Node** head, int newData) {
    // Buat node baru
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    // Jika linked list kosong, jadikan node baru sebagai head
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    // Jika tidak, cari node terakhir
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Hubungkan node terakhir dengan node baru
    last->next = newNode;
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

    // Cetak linked list
    cout << "Isi Linked List: ";
    printList(head); // Output: 5 -> 10 -> 20

    return 0;
}

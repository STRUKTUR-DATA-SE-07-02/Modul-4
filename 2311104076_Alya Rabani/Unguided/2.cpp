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

// Fungsi untuk menghapus node dengan nilai tertentu
void deleteNode(Node** head, int key) {
    // Simpan node head sementara
    Node* temp = *head;
    Node* prev = nullptr;

    // Jika node yang akan dihapus adalah head
    if (temp != nullptr && temp->data == key) {
        *head = temp->next; // Pindahkan head ke node berikutnya
        delete temp; // Hapus node lama
        return;
    }

    // Cari node yang punya nilai tertentu
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // kalau node tidak ditemukan
    if (temp == nullptr) return;

    // Lepaskan node dari linked list
    prev->next = temp->next;

    // Hapus node
    delete temp;
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

    cout << "Linked list sebelum penghapusan: ";
    printList(head);

    // Hapus node dengan nilai tertentu
    deleteNode(&head, 10); 

    cout << "Linked list setelah penghapusan: ";
    printList(head);

    return 0;
}
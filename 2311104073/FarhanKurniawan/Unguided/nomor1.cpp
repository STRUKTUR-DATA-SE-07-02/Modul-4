#include <iostream>
using namespace std;

// Definisi struktur untuk elemen list (Node)
struct Node {
    int data;       // Menyimpan nilai elemen
    Node* next;     // Pointer ke elemen berikutnya
};

// Fungsi untuk menambah node di depan linked list
void insertDepan(Node* &head, int value) {
    Node* newNode = new Node;  // Alokasi memori untuk node baru
    newNode->data = value;     // Mengisi nilai pada node baru
    newNode->next = head;      // Menunjuk ke node pertama sebelumnya
    head = newNode;            // Node baru menjadi head
}

// Fungsi untuk menambah node di belakang linked list
void insertBelakang(Node* &head, int value) {
    Node* newNode = new Node;  // Alokasi memori untuk node baru
    newNode->data = value;     // Mengisi nilai pada node baru
    newNode->next = nullptr;   // Node baru menjadi node terakhir (next = nullptr)

    if (head == nullptr) {     // Jika list kosong
        head = newNode;        // Node baru menjadi node pertama
    } else {
        Node* temp = head;     // Memulai dari head
        while (temp->next != nullptr) {
            temp = temp->next; // Menemukan node terakhir
        }
        temp->next = newNode;  // Menambahkan node baru di akhir
    }
}

// Fungsi untuk mencetak seluruh isi linked list
void cetakList(Node* head) {
    if (head == nullptr) {
        cout << "Linked List kosong!" << endl;
        return;
    }

    Node* temp = head;  // Mulai dari node pertama
    while (temp != nullptr) {
        cout << temp->data;     // Cetak nilai node
        if (temp->next != nullptr) {
            cout << " -> ";     // Cetak panah jika masih ada node berikutnya
        }
        temp = temp->next;      // Pindah ke node berikutnya
    }
    cout << endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr;  // Inisialisasi linked list dengan head sebagai nullptr (kosong)

    // Menambah node berdasarkan contoh input
    insertDepan(head, 10);    // Tambah node di depan dengan nilai 10
    insertBelakang(head, 20); // Tambah node di belakang dengan nilai 20
    insertDepan(head, 5);     // Tambah node di depan dengan nilai 5

    // Mencetak isi linked list
    cout << "Isi Linked List: ";
    cetakList(head);  // Output: 5 -> 10 -> 20

    return 0;
}

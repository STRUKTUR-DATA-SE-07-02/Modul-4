#include <iostream>
using namespace std;

// Deklarasi Struct untuk elemen Linked List
struct Node {
    int data;       // Menyimpan nilai elemen
    Node* next;     // Pointer ke elemen berikutnya
};

Node* head; // Pointer ke elemen pertama

// Inisialisasi List
void init() {
    head = nullptr; // Set head menjadi nullptr
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return head == nullptr; // List kosong jika head adalah nullptr
}

// Menambahkan elemen di awal list
void insertFront(int value) {
    Node* newNode = new Node; // Alokasi memori untuk elemen baru
    newNode->data = value; // Mengisi data node
    newNode->next = head; // Menghubungkan elemen baru ke elemen pertama
    head = newNode; // Menetapkan elemen baru sebagai elemen pertama
}

// Mencari Node dengan Nilai Tertentu
bool searchNode(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true; // Node ditemukan
        }
        current = current->next; // Melanjutkan ke elemen berikutnya
    }
    return false; // Node tidak ditemukan
}

// Hitung Jumlah Node
int countNodes() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++; // Menambah jumlah node
        current = current->next; // Melanjutkan ke elemen berikutnya
    }
    return count; // Mengembalikan jumlah node
}

// Tampilkan List
void display() {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " "; // Menampilkan data elemen
            temp = temp->next; // Melanjutkan ke elemen berikutnya
        }
        cout << endl; // Baris baru setelah menampilkan list
    }
}

// Main function
int main() {
    init();

    // Menambahkan elemen ke dalam list
    insertFront(10);
    insertFront(20);
    insertFront(30);
    display();

    // Mencari node dengan nilai tertentu
    int searchValue = 20;
    if (searchNode(searchValue)) {
        cout << "Node dengan nilai " << searchValue << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << endl;
    }

    // Menghitung jumlah node
    cout << "Jumlah node dalam linked list: " << countNodes() << endl;

    return 0;
}

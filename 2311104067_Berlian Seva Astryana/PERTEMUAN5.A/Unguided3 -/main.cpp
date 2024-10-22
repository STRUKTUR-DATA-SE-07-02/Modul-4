#include <iostream>
using namespace std;

// Definisi Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node di depan
void insertDepan(Node** head_ref, int new_data) {
    // Alokasi node baru
    Node* new_node = new Node();

    // Isi data node baru
    new_node->data = new_data;

    // Hubungkan node baru ke head lama
    new_node->next = *head_ref;

    // Head sekarang menunjuk ke node baru
    *head_ref = new_node;
}

// Fungsi untuk menambah node di belakang
void insertBelakang(Node** head_ref, int new_data) {
    // Alokasi node baru
    Node* new_node = new Node();

    // Isi data node baru
    new_node->data = new_data;
    new_node->next = nullptr;

    // Jika linked list kosong, jadikan node baru sebagai head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // Jika tidak, cari node terakhir
    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Hubungkan node terakhir ke node baru
    last->next = new_node;
}

// Fungsi untuk mencari node dengan nilai tertentu
bool cariNode(Node* head, int key) {
    Node* current = head;  // Inisialisasi node awal
    while (current != nullptr) {
        if (current->data == key)
            return true;  // Node dengan nilai ditemukan
        current = current->next;
    }
    return false;  // Node tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int hitungPanjang(Node* head) {
    int count = 0;  // Inisialisasi hitungan node
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;  // Mengembalikan panjang linked list
}

// Fungsi untuk mencetak seluruh isi linked list
void cetakList(Node* node) {
    while (node != nullptr) {
        cout << node->data;
        if (node->next != nullptr) {
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    // Head dari linked list diinisialisasi sebagai null
    Node* head = nullptr;

    // Menambah node di depan dengan nilai 10
    insertDepan(&head, 10);

    // Menambah node di belakang dengan nilai 20
    insertBelakang(&head, 20);

    // Menambah node di depan dengan nilai 5
    insertDepan(&head, 5);

    // Mencetak linked list
    cout << "Linked List: ";
    cetakList(head);

    // Mencari node dengan nilai tertentu
    int cari = 20;
    if (cariNode(head, cari)) {
        cout << "Node dengan nilai " << cari << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << cari << " tidak ditemukan." << endl;
    }

    // Menghitung panjang linked list
    int panjang = hitungPanjang(head);
    cout << "Panjang linked list: " << panjang << endl;

    return 0;
}

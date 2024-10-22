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

// Fungsi untuk menghapus node dengan nilai tertentu
void hapusNode(Node** head_ref, int key) {
    // Simpan pointer ke head
    Node* temp = *head_ref;
    Node* prev = nullptr;

    // Jika head memiliki nilai yang ingin dihapus
    if (temp != nullptr && temp->data == key) {
        *head_ref = temp->next;  // Ubah head
        delete temp;  // Hapus node head
        return;
    }

    // Cari node dengan nilai tertentu dan simpan node sebelumnya (prev)
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Jika nilai tidak ditemukan
    if (temp == nullptr) {
        cout << "Node dengan nilai " << key << " tidak ditemukan." << endl;
        return;
    }

    // Hapus node
    prev->next = temp->next;
    delete temp;
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

    // Mencetak linked list sebelum penghapusan
    cout << "Linked List sebelum penghapusan: ";
    cetakList(head);

    // Menghapus node dengan nilai 10
    hapusNode(&head, 10);

    // Mencetak linked list setelah penghapusan
    cout << "Linked List setelah penghapusan: ";
    cetakList(head);

    return 0;
}

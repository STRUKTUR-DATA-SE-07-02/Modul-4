#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;       // Data yang disimpan dalam node
    Node* next;     // Pointer ke node berikutnya
};

// Kelas untuk single linked list
class SingleLinkedList {
private:
    Node* head;     // Pointer ke node pertama (head)

public:
    // Constructor
    SingleLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambah node di depan
    void insertDepan(int nilai) {
        Node* newNode = new Node(); // Buat node baru
        newNode->data = nilai;      // Set nilai data
        newNode->next = head;       // Hubungkan node baru ke head saat ini
        head = newNode;             // Set head ke node baru
    }

    // Fungsi untuk menambah node di belakang
    void insertBelakang(int nilai) {
        Node* newNode = new Node(); // Buat node baru
        newNode->data = nilai;      // Set nilai data
        newNode->next = nullptr;    // Node baru akan menjadi node terakhir

        // Jika list kosong, node baru menjadi head
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            // Cari node terakhir
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;  // Hubungkan node terakhir ke node baru
        }
    }

    // Fungsi untuk menghapus node dengan nilai tertentu
    void hapusNode(int nilai) {
        if (head == nullptr) {
            cout << "Linked list kosong!" << endl;
            return;
        }

        // Jika node yang akan dihapus adalah head
        if (head->data == nilai) {
            Node* temp = head;
            head = head->next; // Ubah head ke node berikutnya
            delete temp;       // Hapus node lama
            return;
        }

        // Mencari node yang akan dihapus
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != nilai) {
            prev = temp;
            temp = temp->next;
        }

        // Jika node tidak ditemukan
        if (temp == nullptr) {
            cout << "Node dengan nilai " << nilai << " tidak ditemukan!" << endl;
            return;
        }

        // Hapus node
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk mencetak seluruh isi linked list
    void cetakList() {
        if (head == nullptr) {
            cout << "Linked list kosong!" << endl;
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data;
                if (temp->next != nullptr) {
                    cout << " -> ";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// Fungsi utama
int main() {
    SingleLinkedList list;  // Buat objek single linked list

    // Operasi pada linked list sesuai contoh
    list.insertDepan(10);     // Tambah node di depan (nilai: 10)
    list.insertBelakang(20);  // Tambah node di belakang (nilai: 20)
    list.insertDepan(5);      // Tambah node di depan (nilai: 5)

    // Cetak isi linked list sebelum penghapusan
    cout << "Isi Linked List Sebelum Penghapusan: ";
    list.cetakList();

    // Hapus node dengan nilai tertentu (nilai: 10)
    list.hapusNode(10);

    // Cetak isi linked list setelah penghapusan
    cout << "Isi Linked List Setelah Penghapusan: ";
    list.cetakList();

    return 0;
}

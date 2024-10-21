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

    // Cetak isi linked list
    cout << "Isi Linked List: ";
    list.cetakList();

    return 0;
}

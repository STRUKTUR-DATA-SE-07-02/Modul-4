#include <iostream>
using namespace std;

// Struktur untuk node dalam linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menambah node di depan
    void tambahDepan(int nilai) {
        Node* newNode = new Node(nilai);
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambah node di belakang
    void tambahBelakang(int nilai) {
        Node* newNode = new Node(nilai);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menghapus node dengan nilai tertentu
    void hapusNode(int nilai) {
        if (!head) return;

        if (head->data == nilai) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current && current->data != nilai) {
            prev = current;
            current = current->next;
        }

        if (!current) return;

        prev->next = current->next;
        delete current;
    }

    // Fungsi untuk mencetak linked list
    void cetakList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int pilihan, nilai;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah node di depan\n";
        cout << "2. Tambah node di belakang\n";
        cout << "3. Hapus node dengan nilai tertentu\n";
        cout << "4. Cetak linked list\n";
        cout << "5. Keluar\n";
        cout << "Pilih operasi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                list.tambahDepan(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                list.tambahBelakang(nilai);
                break;
            case 3:
                cout << "Masukkan nilai yang akan dihapus: ";
                cin >> nilai;
                list.hapusNode(nilai);
                break;
            case 4:
                cout << "Isi linked list: ";
                list.cetakList();
                break;
            case 5:
                cout << "Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
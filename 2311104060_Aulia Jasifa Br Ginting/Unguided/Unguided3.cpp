#include <iostream>
using namespace std;

// Struktur untuk node linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    // Constructor
    LinkedList() {
        head = NULL;
    }
    
    // Fungsi untuk menambah node di depan
    void tambahDepan(int nilai) {
        Node* newNode = new Node(nilai);
        newNode->next = head;
        head = newNode;
        cout << "Node dengan nilai " << nilai << " ditambahkan di depan.\n";
    }
    
    // Fungsi untuk menambah node di belakang
    void tambahBelakang(int nilai) {
        Node* newNode = new Node(nilai);
        
        if (head == NULL) {
            head = newNode;
            cout << "Node dengan nilai " << nilai << " ditambahkan di belakang.\n";
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Node dengan nilai " << nilai << " ditambahkan di belakang.\n";
    }
    
    // Fungsi untuk mencari node dengan nilai tertentu
    bool cariNode(int nilai) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == nilai) {
                cout << "Node dengan nilai " << nilai << " ditemukan.\n";
                return true;
            }
            current = current->next;
        }
        cout << "Node dengan nilai " << nilai << " tidak ditemukan.\n";
        return false;
    }
    
    // Fungsi untuk menghitung panjang linked list
    int hitungPanjang() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        cout << "Panjang linked list: " << count << endl;
        return count;
    }
};

int main() {
    LinkedList list;
    int pilihan, nilai;
    
    do {
        cout << "\nMenu Operasi Linked List:\n";
        cout << "1. Tambah node di depan\n";
        cout << "2. Tambah node di belakang\n";
        cout << "3. Cari node\n";
        cout << "4. Hitung panjang linked list\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
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
                cout << "Masukkan nilai yang dicari: ";
                cin >> nilai;
                list.cariNode(nilai);
                break;
                
            case 4:
                list.hitungPanjang();
                break;
                
            case 5:
                cout << "Program selesai.\n";
                break;
                
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}
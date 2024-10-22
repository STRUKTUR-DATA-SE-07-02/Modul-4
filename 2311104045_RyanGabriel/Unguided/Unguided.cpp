// Soal NO 1
#include <iostream>
using namespace std;

// Deklarasi struct Node
struct Node {
    int data;       // Nilai data yang disimpan dalam node
    Node* next;     // Pointer untuk menunjuk ke node berikutnya
};

// Deklarasi pointer head dan tail
Node* head = nullptr;
Node* tail = nullptr;

// Fungsi untuk mengecek apakah linked list kosong
bool isEmpty() {
    return head == nullptr;
}

// Fungsi untuk menambah node di depan
void insertDepan(int nilai) {
    Node* baru = new Node;  // Buat node baru
    baru->data = nilai;     // Isi data pada node baru
    baru->next = nullptr;

    if (isEmpty()) {        // Jika linked list kosong
        head = tail = baru; // Node baru menjadi head dan tail
    } else {                // Jika linked list tidak kosong
        baru->next = head;  // Node baru menunjuk ke node pertama
        head = baru;        // Head diupdate menjadi node baru
    }
}

// Fungsi untuk menambah node di belakang
void insertBelakang(int nilai) {
    Node* baru = new Node;  // Buat node baru
    baru->data = nilai;     // Isi data pada node baru
    baru->next = nullptr;

    if (isEmpty()) {        // Jika linked list kosong
        head = tail = baru; // Node baru menjadi head dan tail
    } else {                // Jika linked list tidak kosong
        tail->next = baru;  // Tail menunjuk ke node baru
        tail = baru;        // Tail diupdate menjadi node baru
    }
}

// Fungsi untuk mencetak seluruh isi linked list
void cetakList() {
    if (isEmpty()) {
        cout << "List kosong!" << endl;
    } else {
        Node* bantu = head;  // Mulai dari head
        while (bantu != nullptr) {
            cout << bantu->data;  // Cetak data
            if (bantu->next != nullptr) {
                cout << " -> ";  // Tambahkan tanda panah jika bukan node terakhir
            }
            bantu = bantu->next; // Lanjut ke node berikutnya
        }
        cout << endl;
    }
}

// Main function
int main() {
    // Tambah node di depan (nilai: 10)
    insertDepan(10);
    // Tambah node di belakang (nilai: 20)
    insertBelakang(20);
    // Tambah node di depan (nilai: 5)
    insertDepan(5);
    // Cetak linked list
    cetakList();  // Output: 5 -> 10 -> 20

    return 0;
}

// -------------------------------------------------------------------------------------------------------------------------------------
// // Soal NO 2
#include <iostream>
using namespace std;

// Deklarasi struct Node
struct Node {
    int data;       // Nilai data yang disimpan dalam node
    Node* next;     // Pointer untuk menunjuk ke node berikutnya
};

// Deklarasi pointer head dan tail
Node* head = nullptr;
Node* tail = nullptr;

// Fungsi untuk mengecek apakah linked list kosong
bool isEmpty() {
    return head == nullptr;
}

// Fungsi untuk menambah node di depan
void insertDepan(int nilai) {
    Node* baru = new Node;  // Buat node baru
    baru->data = nilai;     // Isi data pada node baru
    baru->next = nullptr;

    if (isEmpty()) {        // Jika linked list kosong
        head = tail = baru; // Node baru menjadi head dan tail
    } else {                // Jika linked list tidak kosong
        baru->next = head;  // Node baru menunjuk ke node pertama
        head = baru;        // Head diupdate menjadi node baru
    }
}

// Fungsi untuk menambah node di belakang
void insertBelakang(int nilai) {
    Node* baru = new Node;  // Buat node baru
    baru->data = nilai;     // Isi data pada node baru
    baru->next = nullptr;

    if (isEmpty()) {        // Jika linked list kosong
        head = tail = baru; // Node baru menjadi head dan tail
    } else {                // Jika linked list tidak kosong
        tail->next = baru;  // Tail menunjuk ke node baru
        tail = baru;        // Tail diupdate menjadi node baru
    }
}

// Fungsi untuk menghapus node dengan nilai tertentu
void hapusNode(int nilai) {
    if (isEmpty()) {
        cout << "List kosong, tidak ada yang dihapus!" << endl;
        return;
    }

    // Jika node yang akan dihapus adalah head
    if (head->data == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        // Jika hanya ada 1 node dan sudah dihapus, tail juga harus di-null
        if (head == nullptr) {
            tail = nullptr;
        }
        return;
    }

    // Cari node yang akan dihapus (selain head)
    Node* bantu = head;
    while (bantu->next != nullptr && bantu->next->data != nilai) {
        bantu = bantu->next;
    }

    // Jika node dengan nilai tersebut ditemukan
    if (bantu->next != nullptr) {
        Node* hapus = bantu->next;
        bantu->next = hapus->next;
        if (hapus == tail) { // Jika node yang dihapus adalah tail
            tail = bantu;    // Update tail ke node sebelumnya
        }
        delete hapus;
    } else {
        cout << "Node dengan nilai " << nilai << " tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mencetak seluruh isi linked list
void cetakList() {
    if (isEmpty()) {
        cout << "List kosong!" << endl;
    } else {
        Node* bantu = head;  // Mulai dari head
        while (bantu != nullptr) {
            cout << bantu->data;  // Cetak data
            if (bantu->next != nullptr) {
                cout << " -> ";  // Tambahkan tanda panah jika bukan node terakhir
            }
            bantu = bantu->next; // Lanjut ke node berikutnya
        }
        cout << endl;
    }
}

// Main function
int main() {
    // Tambah node di depan (nilai: 10)
    insertDepan(10);
    // Tambah node di belakang (nilai: 20)
    insertBelakang(20);
    // Tambah node di depan (nilai: 5)
    insertDepan(5);
    // Cetak linked list sebelum penghapusan
    cout << "Sebelum penghapusan:" << endl;
    cetakList();  // Output: 5 -> 10 -> 20
    
    // Hapus node dengan nilai 10
    hapusNode(10);
    // Cetak linked list setelah penghapusan
    cout << "Setelah penghapusan:" << endl;
    cetakList();  // Output: 5 -> 20

    return 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------
// Soal NO 3
#include <iostream>
using namespace std;

// Deklarasi struct Node
struct Node {
    int data;       // Nilai data yang disimpan dalam node
    Node* next;     // Pointer untuk menunjuk ke node berikutnya
};

// Deklarasi pointer head dan tail
Node* head = nullptr;
Node* tail = nullptr;

// Fungsi untuk mengecek apakah linked list kosong
bool isEmpty() {
    return head == nullptr;
}

// Fungsi untuk menambah node di depan
void insertDepan(int nilai) {
    Node* baru = new Node;  // Buat node baru
    baru->data = nilai;     // Isi data pada node baru
    baru->next = nullptr;

    if (isEmpty()) {        // Jika linked list kosong
        head = tail = baru; // Node baru menjadi head dan tail
    } else {                // Jika linked list tidak kosong
        baru->next = head;  // Node baru menunjuk ke node pertama
        head = baru;        // Head diupdate menjadi node baru
    }
}

// Fungsi untuk menambah node di belakang
void insertBelakang(int nilai) {
    Node* baru = new Node;  // Buat node baru
    baru->data = nilai;     // Isi data pada node baru
    baru->next = nullptr;

    if (isEmpty()) {        // Jika linked list kosong
        head = tail = baru; // Node baru menjadi head dan tail
    } else {                // Jika linked list tidak kosong
        tail->next = baru;  // Tail menunjuk ke node baru
        tail = baru;        // Tail diupdate menjadi node baru
    }
}

// Fungsi untuk mencari node dengan nilai tertentu
bool cariNode(int nilai) {
    Node* bantu = head;
    while (bantu != nullptr) {
        if (bantu->data == nilai) {
            return true;    // Node ditemukan
        }
        bantu = bantu->next; // Lanjut ke node berikutnya
    }
    return false;           // Node tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int hitungPanjang() {
    int panjang = 0;
    Node* bantu = head;
    while (bantu != nullptr) {
        panjang++;
        bantu = bantu->next;
    }
    return panjang;
}

// Main function
int main() {
    // Tambah node di depan (nilai: 10)
    insertDepan(10);
    // Tambah node di belakang (nilai: 20)
    insertBelakang(20);
    // Tambah node di depan (nilai: 5)
    insertDepan(5);

    // Cari node dengan nilai 20
    int nilaiCari = 20;
    if (cariNode(nilaiCari)) {
        cout << "Node dengan nilai " << nilaiCari << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << nilaiCari << " tidak ditemukan." << endl;
    }

    // Cetak panjang linked list
    cout << "Panjang linked list: " << hitungPanjang() << endl;

    return 0;
}
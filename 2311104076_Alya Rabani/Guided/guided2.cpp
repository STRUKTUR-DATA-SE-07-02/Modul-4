#include <iostream>
using namespace std;

// Definisi struktur untuk elemen list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk mengalokasi memori untuk node baru
Node* alokasi(int value){
    Node* newNode = new Node;
    if (newNode != nullptr){
        newNode->data = value;
        newNode->next = nullptr;
    }
    return newNode;
}

// fungsi untuk dealokasi memori node
void dealokasi(Node* node){
    delete node;
}
// pengecekan apakah list kosong
bool isListEmpty(Node* head){
    return head == nullptr;
}

// menambahkan elemen diawal list
void insertFirst(Node* &head, int value){
    Node* newNode = alokasi(value);
    if (newNode != nullptr){
        newNode->next = head;
        head = newNode;
    }
}

// menambahkan elemen diakhir list
void insertLast(Node* &head, int value){
    Node* newNode = alokasi(value);
    if (newNode != nullptr){
        if (isListEmpty(head)) {
            head = newNode;
        }
    } else {
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// menampilkan semua elemen dalam list
void printList(Node* head){
    if (isListEmpty(head)){
        cout << "List kosong!" << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// menghitung jumlah elemen dalam list
int countElements(Node* &head){
    int count = 0;
    Node* temp = head;
    while (temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

// menghapus semua elemen dalam list dan dealokasi memori
void clearList(Node* &head){
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        dealokasi(temp);
    }
}

int main(){
    Node* head = nullptr;

    //menambahkan elemen ke dalam list
    insertFirst(head, 10);
    insertLast(head, 20);
    insertLast(head, 30);

    //menampilkan isi list
    cout << "Isi List: ";
    printList(head);

    //menampilkan jumlah elemen
    cout << "Jumlah elemen: " << countElements(head) << endl;

    //menghapus semua elemen dalam list
    clearList(head);

    //menampilkan isi list setelah penghapusan
    cout << "Isi List setelah penghapusan: ";
    printList(head);

    return 0; 
}
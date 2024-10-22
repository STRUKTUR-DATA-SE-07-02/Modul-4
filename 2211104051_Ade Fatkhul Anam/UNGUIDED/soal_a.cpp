#include <iostream>
using namespace std;

// Struktur untuk node
struct Node {
    int data;
    Node *next;
};

// Fungsi untuk menambah node di depan
void insertDepan(Node *&head, int nilai) {
    Node *baru = new Node{nilai, head};
    head = baru;
}

// Fungsi untuk menambah node di belakang
void insertBelakang(Node *&head, int nilai) {
    Node *baru = new Node{nilai, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Fungsi untuk mencetak isi linked list
void cetakList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;
    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);
    cout << "Isi linked list: ";
    cetakList(head);
    return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void insertDepan(Node *&head, int nilai) {
    Node *baru = new Node{nilai, head};
    head = baru;
}

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

bool cariNode(Node *head, int nilai) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == nilai) return true;
        temp = temp->next;
    }
    return false;
}

int hitungPanjang(Node *head) {
    int panjang = 0;
    Node *temp = head;
    while (temp != nullptr) {
        panjang++;
        temp = temp->next;
    }
    return panjang;
}

int main() {
    Node *head = nullptr;
    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);
    
    int nilaiDicari = 20;
    if (cariNode(head, nilaiDicari))
        cout << "Node dengan nilai " << nilaiDicari << " ditemukan." << endl;
    else
        cout << "Node dengan nilai " << nilaiDicari << " tidak ditemukan." << endl;

    cout << "Panjang linked list: " << hitungPanjang(head) << endl;
    return 0;
}
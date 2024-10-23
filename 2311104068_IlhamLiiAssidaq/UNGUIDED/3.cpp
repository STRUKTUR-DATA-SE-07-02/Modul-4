#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertDepan(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

void insertBelakang(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool cariNode(Node* head, int nilai) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == nilai) {
            return true; 
        }
        temp = temp->next;
    }
    return false; 
}

int hitungPanjang(Node* head) {
    int panjang = 0;
    Node* temp = head;
    while (temp != NULL) {
        panjang++;
        temp = temp->next;
    }
    return panjang;
}

int main() {
    Node* head = NULL;

    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);

    int nilaiCari = 20;
    if (cariNode(head, nilaiCari)) {
        cout << "Node dengan nilai " << nilaiCari << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << nilaiCari << " tidak ditemukan." << endl;
    }

    cout << "Panjang linked list: " << hitungPanjang(head) << endl;

    return 0;
}


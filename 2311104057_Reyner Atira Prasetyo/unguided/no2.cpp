#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function untuk menambah node di depan
void insertDepan(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

// Function untuk menambah node di belakang
void insertBelakang(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function untuk mencetak seluruh isi linked list
void cetakList(Node* head) {
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

// Function untuk menghapus node dengan nilai tertentu
void hapusNode(Node*& head, int nilai) {
    if (head == nullptr) return;

    // Jika node pertama adalah node yang akan dihapus
    if (head->data == nilai) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != nilai) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Node dengan nilai " << nilai << " tidak ditemukan." << endl;
    } else {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}

int main() {
    Node* head = nullptr;

    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);
    
    hapusNode(head, 10);
    cetakList(head);  // Output: 5 -> 20

    return 0;
}

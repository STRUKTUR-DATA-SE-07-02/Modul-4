#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL; 

void insertDepan(int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

void insertBelakang(int nilai) {
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

void hapusNode(int nilai) {
    if (head == NULL) {
        cout << "List kosong, tidak ada yang bisa dihapus!" << endl;
        return;
    }

    if (head->data == nilai) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node dengan nilai " << nilai << " berhasil dihapus!" << endl;
        return;
    }

    Node* current = head;
    Node* prev = NULL;
    while (current != NULL && current->data != nilai) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Node dengan nilai " << nilai << " tidak ditemukan!" << endl;
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "Node dengan nilai " << nilai << " berhasil dihapus!" << endl;
}

void cetakList() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertDepan(10);   
    insertBelakang(20); 
    insertDepan(5);     
    cetakList();        

    hapusNode(10);      
    cetakList();        

    return 0;
}


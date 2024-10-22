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

void hapusNode(Node *&head, int nilai) {
    Node *temp = head, *prev = nullptr;
    while (temp != nullptr && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != nullptr) {
        if (prev != nullptr) prev->next = temp->next;
        else head = temp->next;
        delete temp;
    }
}

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
    hapusNode(head, 10);
    cout << "Isi linked list: ";
    cetakList(head);
    return 0;
}
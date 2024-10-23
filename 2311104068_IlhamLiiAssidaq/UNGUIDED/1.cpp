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

    return 0;
}


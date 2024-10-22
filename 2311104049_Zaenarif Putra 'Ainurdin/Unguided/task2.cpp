#include <iostream>

struct Node
{
    int data;
    Node* next;
};


Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Gagal membuat node baru" << std::endl;
        exit(1);
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void addNodeDepan(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void addNodeBelakang(Node*& head, int data) {
    Node* newNode = createNode(data);
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

void deleteNode(Node*& head, int data) {
    if (head == nullptr) return;

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == data) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Node* head = nullptr;

    addNodeDepan(head, 10);

    addNodeBelakang(head, 20);

    addNodeDepan(head, 5);

    std::cout << "Sebelum penghapusan : ";
    printLinkedList(head);

    deleteNode(head, 10);

    std::cout << "Setelah penghapusan : ";
    printLinkedList(head);

    return 0;
}


#include <iostream>

struct Node {
    int data;
    Node* next;
};
// Fungsi untuk menambah node di depan
void addNodeAtFront(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
// Fungsi untuk menambah node di belakang
void addNodeAtBack(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
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
// Fungsi untuk menghapus node dengan nilai tertentu
void deleteNode(Node*& head, int value) {
    Node* temp = head;
    Node* prev = nullptr;
    // Jika node yang akan dihapus adalah head
    if (temp != nullptr && temp->data == value) {
        head = temp->next; // Ubah head
        delete temp; // Hapus node
        return;
    }

    // Mencari node yang akan dihapus
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    // Jika node tidak ditemukan
    if (temp == nullptr) return;

    // Menghapus node
    prev->next = temp->next;
    delete temp;
}
// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << " -> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}
int main() {
    Node* head = nullptr;
    // Menambah node
    addNodeAtFront(head, 10);
    addNodeAtBack(head, 20);
    addNodeAtFront(head, 5);
    // Menghapus node dengan nilai tertentu
    deleteNode(head, 10);
    // Mencetak linked list
    std::cout << "Isi Linked List: ";
    printList(head);
    return 0;
}

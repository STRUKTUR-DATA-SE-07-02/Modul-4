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

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true; // Node ditemukan
        }
        temp = temp->next;
    }
    return false; // Node tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int countLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
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

    // Mencari node dengan nilai tertentu
    int searchValue = 20;
    if (searchNode(head, searchValue)) {
        std::cout << "Node dengan nilai " << searchValue << " ditemukan." << std::endl;
    } else {
        std::cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << std::endl;
    }

    // Menghitung panjang linked list
    int length = countLength(head);
    std::cout << "Panjang linked list: " << length << std::endl;

    return 0;
}

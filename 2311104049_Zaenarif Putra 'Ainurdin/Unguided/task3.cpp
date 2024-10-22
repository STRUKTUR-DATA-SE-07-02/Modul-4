#include <iostream>

struct Node {
    int data;
    Node* next;
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = nullptr;
    }

    void insertAtFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtBack(int value) {
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

    bool searchNode(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true; // Node ditemukan
            }
            temp = temp->next;
        }
        return false; // Node tidak ditemukan
    }

    int countLength() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count; // Mengembalikan jumlah node
    }

    void printList() {
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

    ~SingleLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    SingleLinkedList list;


    list.insertAtFront(10);
    list.insertAtBack(20);   
    list.insertAtFront(5);   

    int valueToSearch = 20; 
    if (list.searchNode(valueToSearch)) {
        std::cout << "Node dengan nilai " << valueToSearch << " ditemukan." << std::endl;
    } else {
        std::cout << "Node dengan nilai " << valueToSearch << " tidak ditemukan." << std::endl;
    }

    int length = list.countLength();
    std::cout << "Panjang linked list: " << length << std::endl;

    return 0;
}
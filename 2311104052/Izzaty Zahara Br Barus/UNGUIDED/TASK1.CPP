#include <iostream>

using namespace std;

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
    void printList() {
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
    cout << "Isi Linked List: ";
    list.printList(); 

    return 0;
}
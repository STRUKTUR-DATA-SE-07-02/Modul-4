#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Head pointer to the linked list
Node *head = nullptr;

// Function to insert a node at the front
void insertDepan(int nilai)
{
    Node *newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the back
void insertBelakang(int nilai)
{
    Node *newNode = new Node();
    newNode->data = nilai;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node with a specific value
void hapusNode(int nilai)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong, tidak ada node untuk dihapus" << endl;
        return;
    }

    // Jika node yang harus dihapus adalah head
    if (head->data == nilai)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node dengan nilai " << nilai << " berhasil dihapus" << endl;
        return;
    }

    // Mencari node dengan nilai tertentu
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr && temp->data != nilai)
    {
        prev = temp;
        temp = temp->next;
    }

    // Jika node tidak ditemukan
    if (temp == nullptr)
    {
        cout << "Node dengan nilai " << nilai << " tidak ditemukan" << endl;
        return;
    }

    // Hapus node
    prev->next = temp->next;
    delete temp;
    cout << "Node dengan nilai " << nilai << " berhasil dihapus" << endl;
}

// Function to print the entire linked list
void cetakLinkedList()
{
    Node *temp = head;
    if (temp == nullptr)
    {
        cout << "Linked list kosong" << endl;
    }
    else
    {
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    // Contoh operasi
    insertDepan(10);    // Tambah node di depan (nilai: 10)
    insertBelakang(20); // Tambah node di belakang (nilai: 20)
    insertDepan(5);     // Tambah node di depan (nilai: 5)

    // Cetak isi linked list sebelum penghapusan
    cetakLinkedList(); // Output: 5 -> 10 -> 20

    // Hapus node dengan nilai tertentu
    hapusNode(10); // Hapus node dengan nilai 10

    // Cetak isi linked list setelah penghapusan
    cetakLinkedList(); // Output: 5 -> 20

    return 0;
}
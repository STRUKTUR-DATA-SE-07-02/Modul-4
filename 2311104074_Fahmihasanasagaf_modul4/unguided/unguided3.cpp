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

// Function to search for a node with a specific value
bool cariNode(int nilai)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == nilai)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to count the length of the linked list
int hitungPanjangLinkedList()
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
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

    // Cetak isi linked list
    cetakLinkedList(); // Output: 5 -> 10 -> 20

    // Mencari node dengan nilai tertentu
    int nilaiDicari = 20;
    if (cariNode(nilaiDicari))
    {
        cout << "Node dengan nilai " << nilaiDicari << " ditemukan." << endl;
    }
    else
    {
        cout << "Node dengan nilai " << nilaiDicari << " tidak ditemukan." << endl;
    }

    // Hitung panjang linked list
    int panjang = hitungPanjangLinkedList();
    cout << "Panjang linked list: " << panjang << endl;

    return 0;
}
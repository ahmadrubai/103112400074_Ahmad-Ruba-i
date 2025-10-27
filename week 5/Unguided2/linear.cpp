#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    Node* linearSearch(int value) {
        Node* current = head;
        int nodeNum = 1;

        cout << "\nProses Pencarian:" << endl;

        while (current != nullptr) {
            cout << "Memeriksa node " << nodeNum << ": " << current->data;

            if (current->data == value) {
                cout << " (SAMA) - DITEMUKAN!" << endl;
                return current;
            }
            
            cout << " (tidak sama)" << endl;
            
            current = current->next;
            nodeNum++;
        }

        cout << "Tidak ada node lagi yang tersisa" << endl;
        return nullptr;
    }

    void printSearchResult(int value, Node* result) {
        if (result != nullptr) {
            cout << "\nHasil: Nilai " << value << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << result << endl;
            cout << "Data node: " << result->data << endl;
            
            if (result->next != nullptr) {
                cout << "Node berikutnya: " << result->next->data << endl;
            } else {
                cout << "Node berikutnya: NULL" << endl;
            }
        } else {
            cout << "\nHasil: Nilai " << value << " TIDAK DITEMUKAN dalam linked list!" << endl;
        }
    }
};

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;

    LinkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "Linked List yang dibuat: ";
    list.display();

    int cari1 = 30;
    cout << "Mencari nilai: " << cari1 << endl;
    Node* hasil1 = list.linearSearch(cari1);
    list.printSearchResult(cari1, hasil1);

    int cari2 = 25;
    cout << "Mencari nilai: " << cari2 << endl;
    Node* hasil2 = list.linearSearch(cari2);
    list.printSearchResult(cari2, hasil2);

    return 0;
}
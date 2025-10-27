#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

    Node* getMiddle(Node* start, Node* end) {
        if (start == nullptr) {
            return nullptr;
        }

        Node* slow = start;
        Node* fast = start; 

        while (fast != end) {
            fast = fast->next;
            if (fast != end) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

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

    Node* binarySearch(int value) {
        Node* start = head;
        Node* end = nullptr;
        int iterasi = 1;

        cout << "\nProses Pencarian:" << endl;

        while (start != end && start->next != end) {
            Node* mid = getMiddle(start, end);

            if (mid == nullptr) {
                break;
            }
            
            cout << "Iterasi " << iterasi++ << ": Mid = " << mid->data << " (indeks tengah)";

            if (mid->data == value) {
                cout << " - DITEMUKAN!" << endl;
                return mid;
            } else if (mid->data < value) {
                cout << " -> Cari di bagian kanan" << endl;
                start = mid->next;
            } else {
                cout << " -> Cari di bagian kiri" << endl;
                end = mid;
            }
        }

        if (start != nullptr && start != end && start->data == value) {
             cout << "Iterasi " << iterasi++ << ": Mid = " << start->data << " (indeks tengah)";
             cout << " - DITEMUKAN!" << endl;
             return start;
        }

        cout << "Tidak ada elemen tersisa" << endl;
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
    cout << "BINARY SEARCH PADA LINKED LIST" << endl;

    LinkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.append(60);

    cout << "Linked List yang dibuat: ";
    list.display();

    int cari1 = 40;
    cout << "Mencari nilai: " << cari1 << endl;
    Node* hasil1 = list.binarySearch(cari1);
    list.printSearchResult(cari1, hasil1);

    int cari2 = 25;
    cout << "Mencari nilai: " << cari2 << endl;
    Node* hasil2 = list.binarySearch(cari2);
    list.printSearchResult(cari2, hasil2);

    return 0;
}
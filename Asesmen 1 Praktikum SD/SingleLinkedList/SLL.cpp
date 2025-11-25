#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    Node *next;
};

Node *head = NULL;

void insertNama(string n) {
    Node *baru = new Node;
    baru->nama = n;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void deleteNama(string n) {
    if (head == NULL) return;

    if (head->nama == n) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node *bantu = head;
    while (bantu->next != NULL && bantu->next->nama != n) {
        bantu = bantu->next;
    }

    if (bantu->next != NULL) {
        Node *hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

void viewList() {
    Node *bantu = head;
    while (bantu != NULL) {
        cout << bantu->nama << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

void hitungGenap() {
    int jumlah = 0;
    Node *bantu = head;
    while (bantu != NULL) {
        if (bantu->nama.length() % 2 == 0) {
            jumlah++;
        }
        bantu = bantu->next;
    }
    cout << "Jumlah nama dengan huruf genap: " << jumlah << endl;
}

int main() {
    int pil;
    string input;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cin >> pil;

        if (pil == 1) {
            cout << "Masukkan nama: ";
            cin >> input;
            insertNama(input);
        }
        else if (pil == 2) {
            cout << "Masukkan nama untuk delete: ";
            cin >> input;
            deleteNama(input);
        }
        else if (pil == 3) {
            viewList();
        }
        else if (pil == 4) {
            hitungGenap();
        }
        else if (pil == 0) {
            
        }

    } while (pil != 0);

    return 0;
}
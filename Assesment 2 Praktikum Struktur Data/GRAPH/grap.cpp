#include <iostream>
#include <string>

using namespace std;

struct Node;

struct Edge {
    Node* tujuan;
    Edge* nextE;
};

struct Node {
    string info;
    Node* nextN;
    Edge* firstE;
    bool visited;
    bool status; 
};

struct Graph {
    Node* head;

    Graph() {
        head = NULL;
    }

    Node* searchNode(string nama) {
        Node* p = head;
        while (p != NULL) {
            if (p->info == nama) return p;
            p = p->nextN;
        }
        return NULL;
    }

    void resetVisit() {
        Node* p = head;
        while (p != NULL) {
            p->visited = false;
            p = p->nextN;
        }
    }

    int countNode() {
        int c = 0;
        Node* p = head;
        while (p != NULL) {
            c++;
            p = p->nextN;
        }
        return c;
    }

    void dfs(Node* curr, int &count) {
        curr->visited = true;
        count++; 

        Edge* e = curr->firstE;
        while (e != NULL) {
            if (!e->tujuan->visited && e->tujuan->status == false) {
                dfs(e->tujuan, count); 
            }
            e = e->nextE;
        }
    }

    void insertNode(string nama) {
        Node* baru = new Node;
        baru->info = nama;
        baru->nextN = NULL;
        baru->firstE = NULL;
        baru->visited = false;
        baru->status = false; 

        if (head == NULL) {
            head = baru;
        } else {
            Node* p = head;
            while (p->nextN != NULL) {
                p = p->nextN;
            }
            p->nextN = baru;
        }
    }

    void connect(string asal, string target) {
        Node* nAsal = searchNode(asal);
        Node* nTujuan = searchNode(target);

        if (nAsal != NULL && nTujuan != NULL) {
            Edge* e1 = new Edge;
            e1->tujuan = nTujuan; 
            e1->nextE = nAsal->firstE;
            nAsal->firstE = e1;

            Edge* e2 = new Edge;
            e2->tujuan = nAsal;   
            e2->nextE = nTujuan->firstE;
            nTujuan->firstE = e2;
        }
    }

    void print() {
        cout << "Membangun Jaringan Distribusi Vaksin" << endl;
        Node* p = head;
        while (p != NULL) {
            cout << "Node " << p->info << " terhubung ke: ";
            Edge* e = p->firstE;
            while (e != NULL) {
                cout << e->tujuan->info << " ";
                e = e->nextE;
            }
            cout << endl;
            p = p->nextN;
        }
        cout << endl;
    }

    void simulasi() {
        cout << "Analisis Kota Kritis (Single Point of Failure)" << endl;
        
        int total = countNode();
        Node* cek = head;

        while (cek != NULL) {
            cek->status = true; 
            
            resetVisit();
            int terhubung = 0; 
            
            Node* start = head;
            if (start == cek) {
                start = start->nextN;
            }

            if (start != NULL) {
                dfs(start, terhubung);
            }

            if (terhubung < total - 1) {
                cout << "[PERINGATAN] Kota " << cek->info << " adalah KOTA KRITIS!" << endl;
                cout << "-> Jika " << cek->info << " lockdown, distribusi terputus." << endl;
            } else {
                cout << "Kota " << cek->info << " aman (redundansi oke)." << endl;
            }

            cek->status = false;
            cek = cek->nextN;
        }
    }
};

int main() {
    Graph g;

    g.insertNode("A");
    g.insertNode("B");
    g.insertNode("C");
    g.insertNode("D");
    g.insertNode("E");

    g.connect("A", "B");
    g.connect("B", "E");
    g.connect("B", "C");
    g.connect("C", "D");

    g.print();
    g.simulasi();

    return 0;
}
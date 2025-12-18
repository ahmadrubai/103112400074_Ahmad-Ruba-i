# <h1 align="center">Laporan Praktikum Modul 14 - Graph (Bagian Pertama)</h1>
<p align="center">Ahmad Ruba'i - 103112400074</p>

## Dasar Teori
Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan. Simpul pada graph disebut dengan verteks (V), sedangkan sisi yang menghubungkan antar verteks disebut edge (E).
### Jenis-jenis Graph
Graph dapat dibedakan berdasarkan arah jelajahnya dan ada tidaknya label bobot pada relasinya.
Berdasarkan arah jelajahnya graph dibagi menjadi Undirected graph dan Directed graph.

### Undirected Graph
Pada undirected graph, simpul-simpulnya terhubung dengan edge yang sifatnya dua arah. Misalnya kita punya simpul 1 dan 2 yang saling terhubung, kita bisa menjelajah dari simpul 1 ke simpul 2, begitu juga sebaliknya.

### Directed Graph
Kebalikan dari undirected graph, pada graph jenis ini simpul-simpulnya terhubung oleh edge yang hanya bisa melakukan jelajah satu arah pada simpul yang ditunjuk. Sebagai contoh jika ada simpul A yang terhubung ke simpul B, namun arah panahnya menuju simpul B, maka kita hanya bisa melakukan jelajah (traversing) dari simpul A ke simpul B, dan tidak berlaku sebaliknya.Selain arah jelajahnya, graph dapat dibagi menjadi 2 berdasarkan ada tidaknya label bobot pada koneksinya, yaitu weighted graph dan unweighted graph.

### Weighted Graph
Weighted graph adalah jenis graph yang cabangnya diberi label bobot berupa bilangan numerik. Pemberian label bobot pada edge biasanya digunakan untuk memudahkan algoritma dalam menyelesaikan masalah.

### Unweighted Graph
Berbeda dengan jenis sebelumnya, unweighted graph tidak memiliki properti bobot pada koneksinya. Graph ini hanya mempertimbangkan apakah dua node saling terhubung atau tidak.

### Karakteristik Graph 
Graph memiliki beberapa karakteristik sebagai berikut:

1. Jarak maksimum dari sebuah simpul ke semua simpul lainnya dianggap sebagai eksentrisitas dari simpul tersebut.
2. Titik yang memiliki eksentrisitas minimum dianggap sebagai titik pusat dari graph.
3. Nilai eksentrisitas minimum dari semua simpul dianggap sebagai jari-jari dari graph terhubung.

### Fungsi dan Kegunaan Graph
Fungsi dan kegunaan graph di antaranya:
1. Graph digunakan untuk merepresentasikan aliran komputasi.
2. Digunakan dalam pemodelan grafik.
3. Graph dipakai pada sistem operasi untuk alokasi sumber daya.
4. Google maps menggunakan graph untuk menemukan rute terpendek.
5. Graph digunakan dalam sistem penerbangan untuk optimasi rute yang efektif.
6. Pada state-transition diagram, graph digunakan untuk mewakili state dan transisinya.
7. Di sirkuit, graph dapat digunakan untuk mewakili titik sirkuit sebagai node dan kabel sebagai edge.
8. Graph digunakan dalam memecahkan teka-teki dengan hanya satu solusi, seperti labirin.
9. Graph digunakan dalam jaringan komputer untuk aplikasi Peer to peer (P2P).
10. Umumnya graph dalam bentuk DAG (Directed acyclic graph) digunakan sebagai alternatif blockchain untuk cryptocurrency. Misalnya crypto seperti IOTA


## Guided 

### 1. ...

```C++ graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct elmEdge {
    adrNode node;
    adrEdge next;
};

struct graph {
    adrNode first;
};

void createGraph(graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(graph &G, infoGraph x);
void connectNode(graph &G, infoGraph start, infoGraph end);
void printGraph(graph G);

#endif
```
```C++ graph_edge.cpp
#include "graph.h"

adrNode findNode (graph G, infoGraph x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p -> info == x) {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

void connectNode (graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new elmEdge;
        newEdge -> node = pEnd;
        newEdge -> next = pStart -> firstEdge;
        pStart -> firstEdge = newEdge;
    }
}
```
```C++ graph_innit.cpp
#include "graph.h"

void createGraph (graph &G) {
    G.first = NULL;
}

adrNode allocateNode (infoGraph x) {
    adrNode P = new elmNode;
    P -> info = x;
    P -> visited = false;
    P -> firstEdge = NULL;
    P -> next = NULL;
    return P;
}

void insertNode (graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q -> next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
}
```
```C++ graph_print.cpp
#include "graph.h"

void printGraph(graph G) {
    adrNode P = G.first;
    while (P!=NULL){
        cout<<"Node"<<P->info<<"terhubung ke:";
        adrEdge E=P->firstEdge;
        while(E!=NULL){
            cout<<E->node->info<<" ";
            E=E->next;
        }
        cout<<endl;
        P=P->next;
    }


}
```
```C++ main.cpp
#include "graph.h"
#include<iostream>
using namespace std;

int main(){
    graph G;
    createGraph(G);

    //menambahkan node A,B,C,D
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    //menghubungkan node
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph"<< endl;
    printGraph(G);

    return 0;
}
```
Graph memiliki fungsi untuk membuat graph, menambah node, menghubungkan node, dan menampilkan hubungan antar node. Pada program utama, node A, B, C, dan D ditambahkan lalu dihubungkan sesuai relasi yang ditentukan, kemudian isi graph dicetak sebagai output.


## Unguided 

### 1. 

```C++ graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);

#endif
```
```C++ graph.cpp
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;

    if (G.first == NULL) {
        G.first = newNode;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}
```
```C++ main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i++) {
        InsertNode(G, nodes[i]);
    }

    ConnectNode(findNode(G, 'A'), findNode(G, 'B'));
    ConnectNode(findNode(G, 'A'), findNode(G, 'C'));
    ConnectNode(findNode(G, 'B'), findNode(G, 'D'));
    ConnectNode(findNode(G, 'B'), findNode(G, 'E'));
    ConnectNode(findNode(G, 'C'), findNode(G, 'F'));
    ConnectNode(findNode(G, 'C'), findNode(G, 'G'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'D'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'E'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'F'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'G'));

    PrintInfoGraph(G);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%2014/103112400074_Ahmad%20Ruba'i/Output%20Unguided%201.png)

Program ini mengimplementasikan ADT Graph tidak berarah menggunakan representasi Adjacency List menggunakan pointer dinamis. Struktur ElmNode sebagai simpul dan ElmEdge sebagai busur, program dapat menambah simpul, menghubungkan dua simpul secara timbal balik (dua arah), serta menampilkan daftar ketetanggaan setiap simpul untuk memverifikasi hubungan antar data yang telah dibangun.

### 2. 

```C++ graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);

#endif
```
```C++ graph.cpp
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;

    if (G.first == NULL) {
        G.first = newNode;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        N->visited = 1;
        cout << N->info << " ";
        adrEdge E = N->firstEdge;
        while (E != NULL) {
            PrintDFS(G, E->Node);
            E = E->Next;
        }
    }
}
```
```C++ main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i++) {
        InsertNode(G, nodes[i]);
    }

    ConnectNode(findNode(G, 'A'), findNode(G, 'B'));
    ConnectNode(findNode(G, 'A'), findNode(G, 'C'));
    ConnectNode(findNode(G, 'B'), findNode(G, 'D'));
    ConnectNode(findNode(G, 'B'), findNode(G, 'E'));
    ConnectNode(findNode(G, 'C'), findNode(G, 'F'));
    ConnectNode(findNode(G, 'C'), findNode(G, 'G'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'D'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'E'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'F'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'G'));

    cout << "Hasil Penelusuran DFS (mulai dari A):" << endl;
    ResetVisited(G);
    PrintDFS(G, findNode(G, 'A'));
    cout << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%2014/103112400074_Ahmad%20Ruba'i/Output%20Unguided%202.png)


Program ini mengimplementasikan ADT Graf tidak berarah menggunakan representasi Adjacency List menggunakan pointer dinamis. Program mendukung penyisipan simpul dan pembentukan hubungan timbal balik, selain itu program ini juga menyertakan algoritma Depth First Search (DFS) untuk menelusuri simpul secara rekursif, serta fungsi untuk mereset status kunjungan simpul guna memastikan akurasi hasil penelusuran.

### 3. 

```C++ graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
```C++ graph.cpp
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;

    if (G.first == NULL) {
        G.first = newNode;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << ": ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        N->visited = 1;
        cout << N->info << " ";
        adrEdge E = N->firstEdge;
        while (E != NULL) {
            PrintDFS(G, E->Node);
            E = E->Next;
        }
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;
    
    queue<adrNode> q;
    N->visited = 1;
    q.push(N);

    while (!q.empty()) {
        adrNode curr = q.front();
        q.pop();
        cout << curr->info << " ";

        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                q.push(E->Node);
            }
            E = E->Next;
        }
    }
}
```
```C++ main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i++) {
        InsertNode(G, nodes[i]);
    }

    ConnectNode(findNode(G, 'A'), findNode(G, 'B'));
    ConnectNode(findNode(G, 'A'), findNode(G, 'C'));
    ConnectNode(findNode(G, 'B'), findNode(G, 'D'));
    ConnectNode(findNode(G, 'B'), findNode(G, 'E'));
    ConnectNode(findNode(G, 'C'), findNode(G, 'F'));
    ConnectNode(findNode(G, 'C'), findNode(G, 'G'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'D'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'E'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'F'));
    ConnectNode(findNode(G, 'H'), findNode(G, 'G'));

    cout << "Hasil Penelusuran DFS (mulai dari A): ";
    ResetVisited(G);
    PrintDFS(G, findNode(G, 'A'));
    cout << endl;

    cout << "Hasil Penelusuran BFS (mulai dari A): ";
    ResetVisited(G);
    PrintBFS(G, findNode(G, 'A'));
    cout << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/ahmadrubai/103112400074_Ahmad-Ruba-i/blob/main/week%2014/103112400074_Ahmad%20Ruba'i/Output%20Unguided%203.png)

Program ini mengimplementasikan ADT Graf tidak berarah secara lengkap menggunakan representasi Adjacency List menggunakan pointer dinamis. Selain operasi dasar seperti penyisipan simpul dan pembentukan hubungan timbal balik, program ini menyertakan dua algoritma penelusuran utama yaitu: DFS yang bekerja secara rekursif untuk menjelajahi kedalaman graf dan BFS yang memanfaatkan antrean (queue) untuk menjelajahi graf berdasarkan level.

## Kesimpulan
Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Simpul pada graph disebut dengan verteks (V), sedangkan sisi yang menghubungkan antar verteks disebut edge (E). Undirected Graph adalah graph yang simpul-simpulnya terhubung dengan edge yang sifatnya dua arah. directed Graph adalah graph yang simpul-simpulnya terhubung oleh edge yang hanya bisa melakukan jelajah satu arah pada simpul yang ditunjuk. Weighted graph adalah jenis graph yang cabangnya diberi label bobot berupa bilangan numerik. unweighted graph  adalah graph yang tidak memiliki properti bobot pada koneksinya.

## Referensi
[1] https://www.trivusi.web.id/2022/07/struktur-data-graph.html <br>

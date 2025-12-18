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
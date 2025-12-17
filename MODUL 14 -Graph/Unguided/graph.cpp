#include "graph.h"
#include <queue>
#include <stack>

static adrNode AlokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

static adrEdge AlokasiEdge(adrNode tujuan) {
    adrEdge E = new ElmEdge;
    E->Node = tujuan;
    E->Next = NULL;
    return E;
}

static void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

static bool HasEdge(adrNode from, adrNode to) {
    adrEdge e = from->firstEdge;
    while (e != NULL) {
        if (e->Node == to) return true;
        e = e->Next;
    }
    return false;
}

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    if (FindNode(G, X) != NULL) return;

    adrNode P = AlokasiNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) Q = Q->Next;
        Q->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 == NULL || N2 == NULL) return;
    if (N1 == N2) return;

    if (!HasEdge(N1, N2)) {
        adrEdge E1 = AlokasiEdge(N2);
        E1->Next = N1->firstEdge;    
        N1->firstEdge = E1;
    }
    if (!HasEdge(N2, N1)) {
        adrEdge E2 = AlokasiEdge(N1);
        E2->Next = N2->firstEdge;     
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) return;

    ResetVisited(G);
    stack<adrNode> S;
    S.push(N);

    cout << "DFS: ";
    bool firstOut = true;

    while (!S.empty()) {
        adrNode u = S.top();
        S.pop();

        if (u->visited == 1) continue;
        u->visited = 1;

        if (!firstOut) cout << " ";
        cout << u->info;
        firstOut = false;

        adrEdge e = u->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) S.push(e->Node);
            e = e->Next;
        }
    }
    cout << endl;
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    ResetVisited(G);
    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    cout << "BFS: ";
    bool firstOut = true;

    while (!Q.empty()) {
        adrNode u = Q.front();
        Q.pop();

        if (!firstOut) cout << " ";
        cout << u->info;
        firstOut = false;

        adrEdge e = u->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) {
                e->Node->visited = 1;
                Q.push(e->Node);
            }
            e = e->Next;
        }
    }
    cout << endl;
}

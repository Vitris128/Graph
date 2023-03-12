#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_LIST 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX_VERTICES];
int hasCircle;

typedef struct Graph
{
    int A[MAX_VERTICES][MAX_VERTICES];
    int n;   
}Graph;

void init_graph(Graph* pG, int n) {
    int i,j;
    pG->n = n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            pG->A[i][j] = 0;
}

void add_edge(Graph* pG, int u, int v) {
    pG->A[u][v] = 1;
    // pG->A[v][u] = 1;
}

int adjacent(Graph* pG, int u, int v) {
    return pG->A[u][v] != 0;
}

typedef struct List
{
    int data[MAX_LIST];
    int size;
}List;

void makeNullList(List* L) {
    L->size = 0;
}
void pushBackList(List* L, int n) {
    L->data[L->size] = n;
    L->size++;
}

int elementAt(List* L, int n) {
    return L->data[n-1];
}

List neighbours(Graph* pG, int u) {
    int i;
    List L;
    makeNullList(&L);
    for(i=1;i<=pG->n;i++) {
        if(adjacent(pG, i, u))
            pushBackList(&L, i);
    }   
    return L;
}

typedef struct Stack
{
    int data[MAX_LIST];
    int size;
}Stack;
void makeNullStack(Stack* S) {
    S->size = 0;
}
void pushStack(Stack* S, int x) {
    S->data[S->size] = x;
    S->size++;
}
int topStack(Stack* S) {
    return S->data[S->size-1];
}
void popStack(Stack* S) {
    S->size--;
}
int emptyStack(Stack* S) {
    return S->size == 0;
}

void depthFirstSearch(Graph* pG, int x) {
    color[x] = GRAY;
    int v;
    for(v=1;v<=pG->n;v++) {
        if(adjacent(pG, x, v)) {
            if(color[v] == WHITE)
                depthFirstSearch(pG, v);
            else if(color[v]==GRAY)
             hasCircle = 1;
        }
    }
    color[x] = BLACK;
}


int main() {
    Graph G;
    int i,u,v,m,n;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for(i=1;i<=m;i++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for(i=1;i<G.n;i++)
        color[i] = WHITE;
    hasCircle = 0;
    for(i=1;i<G.n;i++) {
        if(color[i] == WHITE)
            depthFirstSearch(&G, i);
    }
    if(hasCircle) printf("CIRCLED");
    else printf("NO CIRCLE");
    return 0;
}
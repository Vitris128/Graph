#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_LIST 100



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
int min(int a, int b) {
    return a>=b ? b : a;
}
int num[MAX_VERTICES], min_num[MAX_VERTICES];
int k;
Stack St;
int on_stack[MAX_VERTICES];

void SCC(Graph*pG, int u, int* count) {
    num[u] = k;
    min_num[u] = k;
    k+=1;
    pushStack(&St, u);
    on_stack[u] = 1;
    int v;
    for(v=1;v<=pG->n;v++) {
        if(adjacent(pG, u, v)) {
            if(num[v]<0) {
                SCC(pG, v, count);
                min_num[u]=min(min_num[u],min_num[v]);
            } else if(on_stack[v])
                min_num[u] = min(min_num[u], num[v]);
        }
    }
    if(num[u] ==  min_num[u]) {
        (*count)++;
        int w;
        do {
            w = topStack(&St);
            popStack(&St);
            on_stack[w] = 0;
        }
        while(w!=u);
    }
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
    for(i=1;i<=G.n;i++) {
        num[i] = -1;
    }
    k = 1;
    int count = 0;
    makeNullStack(&St);
    for(i=1;i<=G.n;i++) {
        if(num[i] == -1) {
            SCC(&G, i, &count);
        }
    }
    if(count==1)printf("STRONG CONNECTED");
    else printf("DISCONNECTED");
    return 0;
}
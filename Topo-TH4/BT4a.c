#include <stdio.h>
#define MAX_VERTICES 100
typedef struct Graph{
    int A[MAX_VERTICES][MAX_VERTICES];
    int n;
}Graph;

typedef struct List{
    int size;
    int data[MAX_VERTICES];
}List;

void makeNullList(List* L) {
    L->size = 0;
}

void pushBack(List* L, int n) {
    L->data[L->size] = n;
    L->size++;
}
void pop(List* L) {
    L->size--;
}
int elementAt(List* L, int n) {
    return L->data[n-1];
}

void copyList(List* S1, List* S2) {
    makeNullList(S1);
    int i;
    for(i=1;i<=S2->size;i++) {
        pushBack(S1, elementAt(S2, i));
    }
}

void initGraph(Graph* pG, int n) {
    pG->n = n;
    int i,j;
    for(i=0;i<pG->n;i++)
        for(j=0;j<pG->n;j++)
            pG->A[i][j] = 0;
}

void addEdge(Graph* pG, int u, int v) {
    pG->A[u][v]++;
}


int rank[MAX_VERTICES];

void ranking(Graph* G) {
    int d[MAX_VERTICES];
    int x,u;
    for(u=1;u<=G->n;u++)
        d[u] = 0;
    for(x = 1;x<=G->n;x++)
        for(u=1;u<=G->n;u++)
            if(G->A[x][u] != 0)
                d[u]++;
    List S1, S2;
    makeNullList(&S1);
    for(u=1;u<=G->n;u++)
        if(d[u]==0)
            pushBack(&S1, u);
    int k = 0, i;
    while(S1.size > 0) {
        makeNullList(&S2);
        for(i=1;i<=S1.size;i++) {
            int u = elementAt(&S1, i);
            rank[u] = k;
            int v;
            for(v = 1; v <= G->n;v++)
                if(G->A[u][v] != 0) {
                    d[v]--;
                    if(d[v] == 0)
                        pushBack(&S2, v);
                }
        }
        copyList(&S1, &S2);
        k++;
    }
}

int main() {
    Graph G;
    int i,n,m,u,v;
    // freopen("topo.txt", "r", stdin);
    scanf("%d%d",&n, &m);
    initGraph(&G, n);
    for(i=0;i<m;i++) {
        scanf("%d%d",&u,&v);
        addEdge(&G, v, u);
    }
    ranking(&G);
    int total=0;
    for(i=1;i<=n;i++) {
        printf("%d\n",rank[i]+1);
        total+=rank[i]+1;
    }
    printf("%d",total);
    return 0;
}
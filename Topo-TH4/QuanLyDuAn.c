#include <stdio.h>
#define MAX_VERTICES 100
#define oo 987665432
int d[MAX_VERTICES];

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

void topo_sort(Graph* G,List* L) {
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
    int i;
    while(S1.size > 0) {
        makeNullList(&S2);
        for(i=1;i<=S1.size;i++) {
            int u = elementAt(&S1, i);
            pushBack(L, u);
            int v;
            for(v = 1; v <= G->n;v++)
                if(G->A[u][v] != 0) {
                    d[v]--;
                    if(d[v] == 0)
                        pushBack(&S2, v);
                }
        }
        copyList(&S1, &S2);
    }
}

int max(int a, int b)  {
    return a > b ? a : b;
}

int min(int a, int b)  {
    return a < b ? a : b;
}

int main() {
    Graph G;
    int n,x,u,v,j;
    // freopen("topo_sort.txt", "r", stdin);
    scanf("%d",&n);
    initGraph(&G, n+2);
    int alpha = n+1, beta = n+2;
    d[alpha] = 0;
    for(u=1;u<=n;u++) {
        scanf("%d", &d[u]);
        do {
            scanf("%d",&x);
            if(x>0)
                addEdge(&G, x, u);
        } while(x > 0);
    }
    for(u=1;u<=n;u++) {
        int deg_neg = 0;
        for(x=1;x<=n;x++)
            if(G.A[x][u]>0)
                deg_neg++;
        if(deg_neg == 0)
            addEdge(&G, alpha, u);
    }

    for(u=1;u<=n;u++) {
        int deg_pos = 0;
        for(v=1;v<=n;v++) 
            if(G.A[u][v]>0)
                deg_pos++;
        if(deg_pos == 0)
            addEdge(&G, u, beta);
    }
    List L;
    makeNullList(&L);
    topo_sort(&G, &L);

    int t[MAX_VERTICES];
    t[alpha] = 0;

    for(j=2;j<=L.size;j++) {
        int u = elementAt(&L,j);
        t[u] = 0;
        for(x=1;x<=n;x++) {

            if(G.A[x][u] > 0 ) {
                t[u] = max(t[u], t[x] + d[x]);
            }
        }
    }


    int T[MAX_VERTICES];
    T[beta] = t[beta];
    
    for(j=L.size-1;j>=1;j--) {
        int u = elementAt(&L,j);
        T[u] = +oo;
        for(v=1;v<=G.n;v++)
            if(G.A[u][v] > 0)
                T[u] = min(T[u], T[v] - d[u]);
    }


    for(u=1;u<=n;u++) {
        printf("%d %d\n", t[u], T[u]);
    }

    return 0;
}
#include <stdio.h>
#define MAX_N 100
#define NO_EDGE -1
#define oo 1999
int pi[MAX_N];
int p[MAX_N];
int mark[MAX_N];


typedef struct Graph
{
    int A[MAX_N][MAX_N];
    int n;
}Graph;

void init_Graph(Graph* pG, int n) {
    pG->n = n;
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            pG->A[i][j] = NO_EDGE;
    
}

void add_edge1(Graph* pG, int u, int v, int w) {
    pG->A[u][v] = w;
}
void add_edge2(Graph* pG, int u, int v, int w) {
    pG->A[u][v] = w;
    pG->A[v][u] = w;
}

int adjacent(Graph* pG, int u, int v) {
    return pG->A[u][v] != -1;
}

void Dijkstra(Graph* pG, int s) {
    int v,i,j,u;
    for(u=1;u<=pG->n;u++) {
        mark[u] = 0;
        pi[u] = oo;
    }
    pi[s] = 0;
    p[s] = -1;
    for(i=1;i<=pG->n-1;i++) {
        int min_pi = oo;
        int u = -1;
        for(j=1;j<=pG->n;j++) {
            if(!mark[j] && pi[j]<min_pi) {
                min_pi = pi[j];
                u = j;
            }
        }
        if(u==-1) break;
        mark[u] = 1;
        for(v=1;v<=pG->n;v++) {
            if(pG->A[u][v] != NO_EDGE && !mark[v])
                if(pi[u] + pG->A[u][v] < pi[v]) {
                    pi[v] = pi[u] + pG->A[u][v];
                    p[v] = u;
                }
        }
    }
    
}


int main() {
    Graph G;
    int i,n,m,u,v,w;;
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
    for(i=1;i<=m;i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge2(&G, u,v,w);
    }
    int s,t;
    scanf("%d%d",&s,&t);
    Dijkstra(&G,s);

    if(pi[t]==oo) printf("-1");
    else {
        printf("%d", pi[t]);
    }
    return 0;
}
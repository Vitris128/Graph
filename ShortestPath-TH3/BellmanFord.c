#include <stdio.h>
#define M 1000
#define oo 123456689
int pi[M];
int p[M];
typedef struct {
    int u,v;
    int w;
} Edge;

typedef struct {
    int n,m;
    Edge edges[M];
}Graph;

void init_graph(Graph* pG, int n, int m) {
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph* pG, int u, int v, int w) {
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->edges[pG->m].w = w;
    pG->m++;
}

void BellmanFord(Graph*pG, int s) {
    int u,v,w, it, k;
    for(u=1;u<=pG->n;u++)
        pi[u] = oo;
    pi[s] = 0;
    p[s] = -1;

    for(it=1;it<pG->n;it++) {
        for(k=0;k<pG->m;k++) {
            u = pG->edges[k].u;
            v = pG->edges[k].v;
            w = pG->edges[k].w;
            if(pi[u] == oo)
                continue;
            if(pi[u]+w < pi[v]) {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
}
int main() {
    Graph G;
    int i,n,m,u,v,w,s,t;
    // freopen("dothi.txt","r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for(i=1;i<=m;i++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    scanf("%d%d", &s, &t);
    BellmanFord(&G, s);
    if(pi[t] == oo) 
        printf("-1");
    else printf("%d", pi[t]);
    return 0;
}
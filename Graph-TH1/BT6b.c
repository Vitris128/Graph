#include <stdio.h>

#define M_MAX 500
typedef struct {
    int u,v;
} Edge;

typedef struct {
    int n,m;
    Edge edges[M_MAX];
}Graph;

void init_graph(Graph* G, int n) {
    G->n = n;
    G->m = 0;
}
void add_edge(Graph* G, int u, int v) {
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->m++;
}
int degree(Graph* G, int u) {
    int e,deg=0;
    for(e=0;e<G->m;e++) {
        if(G->edges[e].u == u)
        deg++;
        if(G->edges[e].v == u)
        deg++;
    }
    return deg;
}
void add_edge_manual(Graph* G) {
	int e,n,m;
	scanf("%d%d\n",&n,&m);
	init_graph(G,n);
	for(e=0;e<m;e++) {
		int u,v;
		scanf("%d%d",&u, &v);
		add_edge(G, u, v);
	}
}

void neighbours(Graph* G, int u) {
	int e, list[G->n+1];
	for(e=1;e<=G->n;e++)
	list[e] = 0;
	for(e=0;e<G->m;e++) {
		if(G->edges[e].u == u) {
			list[G->edges[e].v] = G->edges[e].v;
//				printf("%d ",G->edges[e].v);
		}
//		else if(G->edges[e].v == u) {
//			list[G->edges[e].u] = G->edges[e].u;
////				printf("%d ",G->edges[e].u); 
//		}
	}	
	
	for(e=1;e<=G->n;e++) {
		if(list[e]!=0)
		printf("%d ",list[e]);
	}
	printf("\n");
}
int main() {
    Graph G;
    int u;
//    freopen("dt.txt","r", stdin);
    add_edge_manual(&G);
    for (u = 1; u <=G.n; u++) {
		printf("neighbours(%d) = ",u);
        neighbours(&G,u);
		}
        
    return 0;
}

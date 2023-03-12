#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph* G, int n) {
	G->n = n;
	G->m = 0;
	int i,j;
	for(i=0;i<G->n;i++)
		for(j=0;j<G->n;j++)
			G->A[i][j] = 0;
}

void add_edge(Graph* G, int u, int v) {
	if(u==v) {
	    G->A[u][v]++;
	    G->m++;
	    return;
	}
	G->A[u][v]++;
	G->A[v][u]++;
	G->m++;
}
int degree(Graph* G, int u) {
    int v,deg = 0;
    for(v=1;v<=G->n;v++) {
		deg+=G->A[u][v];
    }
    return deg;
}

int main() {
    Graph G;
    int e, n, m, u, v;

    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    int max_deg_v = 0, max_deg = 0;
    for(n=1;n<=G.n;n++) {
    	int deg = degree(&G, n);
    	if(deg> max_deg)  {
    		max_deg_v = n;
    		max_deg = deg;
		}
	}
	printf("%d %d\n", max_deg_v, max_deg);
    
    return 0;
}

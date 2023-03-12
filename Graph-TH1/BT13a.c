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
	G->m++;
}

void neighbours(Graph* G, int u) {
	int v;
	for(v=1;v<=G->n;v++) {
		if(G->A[u][v]>0)
		printf("%d ",v);
	}
	printf("\n");
}

int main() {
    Graph G;
    int i, j, n, m;

    scanf("%d", &n);
    init_graph(&G, n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) {
			scanf("%d", &m);
			G.A[i][j] += m;
		}
		
	for(i=1;i<=G.n;i++) {
		for(j=1;j<=G.n;j++) {
			for(m=G.A[i][j];m>0;m--) {
				if(i<=j)
				printf("%d %d\n",i, j);
			}
		}
	}
		
    return 0;
}

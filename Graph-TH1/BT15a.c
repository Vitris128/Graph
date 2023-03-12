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
//	G->A[v][u]++;
	G->m++;
}

int main() {
    Graph G;
    int i, j, n, m;

    scanf("%d", &n);
    init_graph(&G, n);
	for(i=1;i<=n;i++) {
		j=1;
		while(1){
			scanf("%d",&m);
			if(m==0) break;
			add_edge(&G,i,m);
//			printf("%d ",G.A[i][j]);
//			printf("%d ",G.A[j][i]);
			j++;
		}
	}
	
	for(i=1;i<=G.n;i++) {
		for(j=1;j<=G.n;j++) {
			printf("%d ",G.A[i][j]);
		}
		printf("\n");
	}
			
    return 0;
}

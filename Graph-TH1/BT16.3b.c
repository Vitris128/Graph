#include <stdio.h>
#define MAX_N 100
#define MAX_M 500

typedef struct {
	int A[MAX_N][MAX_M];
	int n,m;
}Graph;

void init_graph(Graph* pG, int n, int m) {
	pG->n = n;
	pG->m = m;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			pG->A[i][j] = 0;
}

void add_edge(Graph* pG, int e, int x, int y) {
	pG->A[x][e] = 1;
	pG->A[y][e] = -1;
}

int degree(Graph* pG, int x) {
	int deg=0, e;
	for(e=1;e<=pG->m;e++)
		deg+=pG->A[x][e];
	return deg;
}

int adjacent(Graph* pG, int x, int y) {
	int e;
	for(e=1;e<=pG->m;e++) {
		if(pG->A[x][e] == 1 && pG->A[y][e] == 1)
		return 1;
	}
	return 0;
}

void neighbours(Graph* pG, int x) {
	int n;
	for(n=1;n<=pG->n;n++) {
		if(n==x) continue;
		if(adjacent(pG, x, n))
		printf("%d ", n);
	}
	printf("\n");
}

int main() {
	Graph G;
	int e, n, m, u, v;
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for(e=1;e<=m;e++) {
		scanf("%d%d",&u, &v);
		add_edge(&G, e, u, v);
	}
	printf("Ma tran dinh - cung: \n");
	for(u=1;u<=G.n;u++) {
		for(v=1;v<=G.m;v++) {
			printf("%2d ", G.A[u][v]);
		}
		printf("\n");
	}
	
	return 0;
}

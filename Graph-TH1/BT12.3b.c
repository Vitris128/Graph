#include <stdio.h>
#define MAX_N 100
#define MAX_M 500

typedef struct {
	int data[MAX_N];
	int size;
}List;

typedef struct {
	List adj[MAX_N];
	int n,m;
}Graph;

void make_null(List* L) {
    L->size = 0;
}
void push_back(List* L, int x) {
    L->data[L->size] = x;
    L->size++;
}
int element_at(List* L, int i) {
    return L->data[i-1];
}
int size(List* L) {
    return L->size;
}

void init_graph(Graph* pG, int n, int m) {
	int u;
	pG->n = n;
	for(u=1;u<=n;u++)
		make_null(&pG->adj[u]);
}

void add_edge(Graph* pG, int x, int y) {
	push_back(&pG->adj[x], y);
//	push_back(&pG->adj[y], x);
}
int degree(Graph* pG, int x) {
	return size(&pG->adj[x]);
}

int adjacent(Graph* pG, int x, int y) {
	int j;
	for(j=1; j<=size(&pG->adj[x]);j++)
		if(element_at(&pG->adj[x], j) == y)
			return 1;
	return 0;
}

void neighbours(Graph* pG, int x) {
	int j;
	for(j=1;j<=size(&pG->adj[x]);j++)
		printf("%d ",element_at(&pG->adj[x], j));
	printf("\n");
}
void print(Graph* pG) {
	int n ;
	for(n=1;n<=pG->n;n++) {
		neighbours(pG, n);
	}
}

int main() {
	Graph G;
	int e, n, m, x, y;
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	
	for(e=1;e<=m;e++) {
		scanf("%d%d",&x,&y);
		add_edge(&G, x, y);
	}
	printf("Danh sach ke: \n");
	print(&G);
	return 0;
}



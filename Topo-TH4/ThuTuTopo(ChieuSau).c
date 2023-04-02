#include <stdio.h>

#define MAX_N 100
typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;


void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
}


typedef struct {
    int data[MAX_N];
    int size;
} List;

void make_null_list(List *pL) {
    pL->size = 0;
}

void push_back(List *pL, int x) {
    pL->data[pL->size++] = x;
}

int element_at(List *pL, int i) {
    return pL->data[i-1];
}

int mark[MAX_N];

void dfs(Graph *pG, int u, List *pL) {
    mark[u] = 1;
    for (int v = 1; v <= pG->n; v++)
        if (pG->A[u][v] > 0 && !mark[v])
            dfs(pG, v, pL);
    push_back(pL, u);
}
    

void topo_sort(Graph *pG, List *pL) {
	//Khởi tạo chưa đỉnh nào được duyệt cả
	for (int u = 1; u <= pG->n; u++)
		mark[u] = 0;

	//Làm rỗng danh sách pL
	make_null_list(pL);

	//Duyệt cả đồ thị
	for (int u = 1; u <= pG->n; u++)
		if (mark[u] == 0)
			dfs(pG, u, pL);
}

int main() {
    Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	List L;
	topo_sort(&G, &L);
	//In ngược
	for (int i = L.size; i>=1; i--)
	    printf("%d ", element_at(&L, i));
	
	return 0;
}

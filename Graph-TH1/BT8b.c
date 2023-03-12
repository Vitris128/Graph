void add_edge(Graph* G, int u, int v) {
	G->A[u][v]++;
	G->m++;
}

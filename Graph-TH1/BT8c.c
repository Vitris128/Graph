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

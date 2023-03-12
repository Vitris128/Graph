void init_graph(Graph* pG, int n, int m) {
	int u;
	pG->n = n;
	for(u=1;u<=n;u++)
		make_null(&pG->adj[u]);
}

void add_edge(Graph* pG, int x, int y) {
	if(x == y) {
		push_back(&pG->adj[x], y);
		return;
	}
	push_back(&pG->adj[x], y);

}

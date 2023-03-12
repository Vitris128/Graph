void add_edge(Graph* pG, int x, int y) {
	push_back(&pG->adj[x], y);
}

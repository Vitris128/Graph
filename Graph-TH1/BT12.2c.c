void add_edge(Graph* pG, int x, int y) {
	if(x == y) {
		push_back(&pG->adj[x], y);
		return;
	}
	push_back(&pG->adj[x], y);
	push_back(&pG->adj[x], x);
}

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
	pG->A[y][e] = 1;
}

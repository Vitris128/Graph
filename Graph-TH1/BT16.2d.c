void add_edge(Graph* pG, int e, int x, int y) {
	if(x ==y) 
		pG->A[x][e] = 2;
	else
	 {
	pG->A[x][e] = 1;
	pG->A[y][e] = -1;
	 }
}

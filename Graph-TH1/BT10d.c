int outdegree(Graph* G, int u) {
    int v,deg = 0;
    for(v=1;v<=G->n;v++) {
        deg+= G->A[u][v];
    }
    return deg;
}

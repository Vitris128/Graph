void add_edge(Graph* G, int u, int v) {
    int e;
    for(e=0;e<G->m;e++) {
        if(G->edges[e].u == u && G->edges[e].v == v)
        return;
    }
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->m++;
}

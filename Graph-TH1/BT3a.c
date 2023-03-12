void add_edge(Graph* G, int u, int v) {
    if(u<1 || v<1 || v>G->n || u>G->n)
    return;
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->m++;
}

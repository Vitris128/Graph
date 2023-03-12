#include <stdio.h>
#define MAX_N 100
typedef struct Graph
{
    int A[MAX_N][MAX_N];
    int n;
}Graph;


typedef struct Queue
{
    int data[MAX_N];
    int front,rear;
}Queue;

void makeNUllQueue(Queue* Q) {
    Q->front = 0;
    Q->rear = -1;
}
void init_Graph(Graph* pG, int n) {
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            pG->A[i][j] = 0;
    pG->n = n;
}

void add_Edge(Graph* pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
}

int adjacent(Graph* pG, int u, int v){
    return pG->A[u][v];
}
int empty(Queue* Q) {
    return Q->front > Q->rear;
}
void pushBack(Queue* Q, int u) {
    Q->rear++;
    Q->data[Q->rear] = u;
}

int top(Queue* Q) {
    return Q->data[Q->front];
}
void pop(Queue* Q) {
    Q->front++;
}

int mark[MAX_N];
void BFS(Graph* pG, int u) {
    Queue Q;
    int v;
    makeNUllQueue(&Q);
    pushBack(&Q, u);
    while(!empty(&Q)) {
        u = top(&Q);
        pop(&Q);
        if(mark[u]==1) continue;
        printf("%d\n", u);
        mark[u] = 1;
        for(v=1;v<=pG->n;v++) {
            if(adjacent(pG, u, v) && mark[v] ==0)
                pushBack(&Q, v);
        }
    }
}

int main() {
    Graph G;
    int i,n,m,u,v;
    scanf("%d%d", &n,&m);
    init_Graph(&G, n);

    for(i=0;i<m;i++) {
        scanf("%d%d", &u, &v);
        add_Edge(&G, u, v);
    }

    for(i=1;i<=n;i++)
        mark[i] = 0;

    for(i=1;i<=n;i++)
        if(mark[i]==0)
            BFS(&G, i);

    return 0;
    
}
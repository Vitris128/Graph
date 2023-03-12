#include <stdio.h>

#define MAX_Vertices 20
#define MAX_Length 20
#define MAX_Element 40

//Structure of Graph
typedef struct {
	int A[MAX_Vertices][MAX_Vertices];
	int n; //Number of Vertex
} Graph;

//Initialize a new graph
void init_Graph(Graph *G, int n) {
	int i,j;
	G->n = n;
	for(i=1;i<=n;i++)  //Row
		for(j=1;j<=n;j++)  //Column
			G->A[i][j] = 0;
}

//Add new edge
void add_Edge(Graph* G, int x, int y) {
	G->A[x][y] = 1;
	G->A[y][x] = 1; 
}

//Neighbour check
int adjecent(Graph* G, int x, int y) {
	return G->A[x][y] != 0;	
}

//Degree of  vertex x 
int degree(Graph* G, int x) {
	int i,deg = 0;
	for(i=1;i<=G->n;i++) 
		if(adjecent(G, x, i)) 
		deg++;

	return deg;
}

//Structure of List
typedef struct {
	int data[MAX_Length];
	int size;
}List;

//Initialize List
void make_NULL(List* list) {
	list->size = 0;
}

//Add new element to list
void push_Back(List* list, int x) {
	list->data[list->size] = x;
	list->size++;
}

//Return the element at position ith 
int element_At(List* list, int i) {
	return list->data[i-1];
}

//Neighbour of x
List neighbors(Graph* G, int x) {
	int i;
	List L;
	make_NULL(&L);
	for(i=1;i<=G->n;i++) {
		if(adjecent(G, x, i)) 
		push_Back(&L, i);
	}
	return L;
}

//Structure of Queue
typedef struct {
	int data[MAX_Element];
	int front, rear; //Front -> Starting , Rear -> Ending	
}Queue;
//Initialize Queue 
void make_NULL_Queue(Queue* Q) {
	Q->front = 0;
	Q->rear = -1;
}
//Add new element to Queue
void push_Queue(Queue* Q, int x) {
	Q->rear++;
	Q->data[Q->rear] = x;
}
//Check NULL Queue
int empty_Queue(Queue* Q) {
	return Q->front > Q->rear;
}
//Get top element from Queue
int top(Queue* Q) {
	return Q->data[Q->front];
}
void pop(Queue* Q) {
	Q->front++;
}


//Initialize BFS

void breath_First_Search(Graph* G, int x, int mark[], int parent[]) {
	Queue Q;
	int i;
	make_NULL_Queue(&Q);
	push_Queue(&Q,x);
	while(!empty_Queue(&Q)) {
		int u = top(&Q);
		pop(&Q);
		if(mark[u] == 1)
			continue;
		// printf("%d %d\n",u, parent[u]);
		mark[u] = 1;
		List L;
		make_NULL(&L);
		L = neighbors(G, u);
		for(i=1;i<=L.size;i++) {
			int v = element_At(&L,i);
			if(mark[v] ==0) {
				if(parent[v] == -1)
					parent[v] = u;
				push_Queue(&Q,v);
			}
		}
	}
}

int main() {
	Graph G;
// 	freopen("BFS.txt","r",stdin);
	int n,m,i;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int u,v, mark[n+1], parent[n+1];
	for(i=1;i<=m;i++) {
		scanf("%d%d", &u, &v);
		add_Edge(&G, u, v);
	}
	for(i=1;i<=n;i++) {
		mark[i] = 0;
		parent[i] = -1;
	}
	breath_First_Search(&G, 1, mark, parent);
	for(i=1;i<=n;i++) {
		if(mark[i] == 0) 	
	breath_First_Search(&G, i, mark, parent);
			
	}
	for(i=1;i<=n;i++) {
		printf("%d %d\n", i, parent[i]);
	}
	
	return 0;
}
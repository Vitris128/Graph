#include <stdio.h>
#define MAX_N 100
#define NO_EDGE -1
#define oo 1999
int pi[MAX_N];
int p[MAX_N];
int mark[MAX_N];


typedef struct Graph
{
    int A[MAX_N][MAX_N];
    int n,m;
}Graph;

void init_Graph(Graph* pG, int n, int m) {
    pG->n = n;
    pG->m = m;
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            pG->A[i][j] = NO_EDGE;
    
}

void DijkstraRobot(Graph* pG, int N, int M) {
    int v,i,j,u;
    
    for(u=1;u<=pG->n*pG->m;u++) {
        mark[u] = 0;
        pi[u] = oo;
        p[u] = 0;
    }
    pi[1] = 0;
    p[1] = -1;
    int ii,jj;
    int di[] = {-1,1,0,0};
    int dj[] = {0,0,-1,1};

    for(i=1;i<pG->n*pG->m;i++) {
        int min_pi = oo;
        for(j=1;j<=pG->n*pG->m;j++) {
            if(!mark[j] && pi[j]<min_pi) {
                min_pi = pi[j];
                u = j;
            }
        }
        mark[u] = 1;
        
        int i = (u-1)/M;
        int j = (u-1)%M;
        int k;
        for(k=0;k<4;k++) {
            ii = i+di[k];
            jj = j+dj[k];
            if(ii>=0 && ii<N && jj>=0 && jj<M) {
                v = ii*M+jj+1;
                if(pi[u] + pG->A[ii][jj] < pi[v] && !mark[v]) {
                    pi[v] = pi[u] + pG->A[ii][jj];
                    p[v] = u;
                }
            }
        }
    }
}


int main() {
    Graph G;
    int i,j,n,m;
    scanf("%d%d", &n, &m);
    init_Graph(&G, n, m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d", &G.A[i][j]);
    
    DijkstraRobot(&G,n,m);
    printf("%d ", pi[n*m]);
    return 0;
}
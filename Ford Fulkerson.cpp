/// Not Complete 
// Some error here

#include <bits/stdc++.h>
using namespace std;

#define int_max 1e8;
#define N 100
#define V 6 // vertex 6
int graph[V][V];
int vertex, edge;
int src = 1;
int sink = 6;
int flow[N][N];
bool visited[N];
int parent[N];
int rGraph[N][N];


// bfs to find paht p
bool bfs(){
    for(int i=0; i<vertex; i++){
        visited[i]=false;
    }

    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<N; i++){
            if(graph[x][i]>0 && visited[i]== false){
                if(i==sink){ // found a path
                    parent[i]=x;
                    return true;
                }
                parent[i]=x;
                visited[i]=true;
                q.push(i);
            }
        }
    }

    // if no path
    return false;
}

int ford_fulkerson(){
    //initialize flow
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            if(graph[i][j] != -1){
                flow[i][j]=0;
                flow[j][i]=0;
            }
        }
    }

    //residual graph
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            rGraph[i][j] = graph[i][j];
        }
    }

    //
    int maximum_flow = 0; // initialization of max flow as 0

    while(bfs()){
        int path_flow = int_max;
        
        // find min residual capacity
        for(int v=sink; v!=src; v=parent[v]){
            int u = parent[v];
            path_flow = min(path_flow,rGraph[u][v]);
        }

        // update residual capabilities
        for(int v=sink; v!=src; v=parent[v]){
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // add to max flow
        maximum_flow += path_flow;
    }

    return maximum_flow;
}


int main(void){
    // freopen("input.txt", "r", stdin);
    // // input graph
    // cin>>vertex>>edge;

    // for(int i=0; i<edge; i++){
    //     int a, b, weight;
    //     cin>>a>>b>>weight;

    //     graph[a][b]=weight;
    // }

    graph[6][6]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };

    int maxFlow = ford_fulkerson();
    cout<<maxFlow;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int_max 10000;
#define N 100
int graph[N][N]={-1};
int flow[N][N]={0}; // initialize flow as 0
bool visited[N];
int parent[N];
int rGraph[N][N];


//bfs to find paht p
bool bfs(int src, int sink){
    for(int i=0; i<N; i++){
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
            if(rGraph[x][i]>0 && visited[i]== false){
                if(i==sink){ // found a path
                    parent[i]=x;
                    return true;
                }
                visited[i]=true;
                parent[i]=x;
                q.push(i);
            }
        }
    }

    // if no path
    return false;
}


int ford_fulkerson(int src, int sink){

    //residual graph
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            rGraph[i][j] = graph[i][j];
        }
    }

    int maximum_flow = 0; // initialization of max flow as 0

    while(bfs(src,sink)){
        int path_max_flow = int_max; // here the the augmenting path's maximum flow will be stored
        
        // find min residual capacity
        for(int v=sink; v!=src; v=parent[v]){
            int u = parent[v];
            path_max_flow = min(path_max_flow,rGraph[u][v]);
        }

        // update residual capabilities
        for(int v=sink; v!=src; v=parent[v]){
            int u = parent[v];
            rGraph[u][v] -= path_max_flow;
            rGraph[v][u] += path_max_flow;
        }

        // add to max flow
        maximum_flow += path_max_flow;
    }

    return maximum_flow;
}


int main(void){
    freopen("fordFulkerson.txt", "r", stdin);
    // input graph
    int edge, vertex;
    //cout<<"Enter edge and vertex number: ";
    cin>>edge>>vertex;
    cout<<endl;

    //cout<<"Enter vertices and their capacity: \n";
    for(int i=0; i<edge; i++){
        int a, b, capacity;
        cin>>a>>b>>capacity;
        graph[a][b]=capacity;
        cout<<endl;
    }

    // we let src = 0 and sink = 6
    int src = 0;
    int sink = 5;

    cout<<"Maximum flow is: "<<ford_fulkerson(src,sink);

    return 0;
}
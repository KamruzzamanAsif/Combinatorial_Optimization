#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int_max 10000;
#define N 100
int graph[N][N]={-1}; // main graph
int flow[N][N]={0};   // initialize flow as 0
bool visited[N];      // for bfs in finding augmenting path
int parent[N];        // for augmenting path
int rGraph[N][N];     // residual graph
int numberOfVertics;  // for main graph
int numberOfEdges;    // for main graph


void inputGraph(){
    
    //cout<<"Enter total number of vertics and edges: ";
    cin>>numberOfVertics>>numberOfEdges;
    cout<<endl;

    //cout<<"Enter two vertices and their edge capacity: \n";
    for(int i=0; i<numberOfEdges; i++){
        int a, b, capacity;
        cin>>a>>b>>capacity;
        graph[a][b]=capacity;
        cout<<endl;
    }
}

void makeResidualGraph(){
    for(int i=0; i<numberOfVertics; i++){
        for(int j=0; j<numberOfVertics; j++){
            rGraph[i][j] = graph[i][j];
        }
    }
}

bool bfs(int source, int sink){
    // make visited false for all
    for(int i=0; i<N; i++){
        visited[i]=false;
    }

    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

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

int fordFulkerson(int source, int sink){
    makeResidualGraph();

    int maximum_flow = 0; 
    while(bfs(source,sink)){
        int path_max_flow = int_max; // here the the augmenting path's maximum flow will be stored
        
        // find min residual capacity
        for(int v=sink; v!=source; v=parent[v]){
            int u = parent[v];
            path_max_flow = min(path_max_flow,rGraph[u][v]);
        }

        // update residual capabilities
        for(int v=sink; v!=source; v=parent[v]){
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

    inputGraph();

    int source = 0;
    int sink = numberOfVertics-1;
   
    int maximumFlow = fordFulkerson(source, sink);
    cout<<"Maximum flow is: "<<maximumFlow;
    

   return 0;
}
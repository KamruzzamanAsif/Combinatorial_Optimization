#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100
int minCost = 0;
struct node{
    int u;
    int v;
    int w;
}G[N];
int parent[N];

void makeSet(int t_vertices){
    for(int i=0; i<t_vertices; i++)
        parent[i]=i;
    
    return;
}

bool cmp(struct node x, struct node y){
    return x.w <= y.w;
}

int findSet(int s){    // finding the root of the tree
    if(parent[s]==s)
        return s;
    findSet(parent[s]);
}

void Union(int s1, int s2){
    int root_s1, root_s2;
    root_s1 = findSet(s1);
    root_s2 = findSet(s2);
    parent[root_s1] = root_s2;  // making one tree from two different trees
}

int main(void){
    freopen("kruskal.txt", "r", stdin);
    int t_vertices, t_edges;
    cin>>t_vertices>>t_edges; // taking total vertices and edges

    for(int i=0; i<t_edges; i++){
        cin>>G[i].u>>G[i].v>>G[i].w;
    }

    makeSet(t_vertices);

    sort(G, G+t_edges, cmp);

    cout<<"The edges of MST are: "<<endl;
    for(int i=0; i<t_edges; i++){
        if(findSet(G[i].u) != findSet(G[i].v)){
            Union(G[i].u, G[i].v);
            minCost += G[i].w;
            cout<<"( "<<G[i].u<<", "<<G[i].v<<" )"<<" = "<<G[i].w<<endl;
        }
    }

    cout<<"Minmum cost is: "<<minCost<<endl;

    return 0;
}
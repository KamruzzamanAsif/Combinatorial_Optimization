#include <iostream>
using namespace std;
#include <limits.h>

#define N 100
int V; //vertices
int E; //edges
int graph[N][N] = {0}; // graph;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}


void dijkstra(int src)
{
	int dist[V]; // The output array. dist[i] will hold the shortest

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// pick min
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// do relax
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}


int main()
{
    freopen("dijkstra.txt", "r", stdin);

    cout<<"Enter total number of vertices: ";
    cin>>V;

    cout<<"\nEnter total number of edges: ";
    cin>>E;

    cout<<"\nEnter source: ";
    int src;
    cin>>src;

    cout<<"\nEnter u and v and weight:\n";
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u][v] = w;
    }

	dijkstra(src);

	return 0;
}


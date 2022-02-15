#include <bits/stdc++.h>
using namespace std;
int graph[100][100];
int parent[100];
int key[100];
bool inQueue[100];

int extractMinKeyVertex(int v)
{
	int temp = INT_MAX, temp_index;
	for (int i = 0; i<v; i++){
		if (inQueue[i] == true && key[i] < temp){
            temp = key[i];
            temp_index = i;
        }
    }

	return temp_index;
}

void MST_prim(int v)
{
	for (int i = 0; i < v; i++){
		key[i] = INT_MAX;
        inQueue[i] = true;
    }

	key[0] = 0;
	parent[0] = -1;

    // Queue operation begins
	for (int count = 0; count < v- 1; count++)
	{
		int u = extractMinKeyVertex(v);
		inQueue[u] = false;

		for (int i=0; i<v; i++){
            if (graph[u][i] && inQueue[i] == true && graph[u][i] < key[i])
				parent[i] = u, key[i] = graph[u][i];
        }	
	}

    return;
}

void printMST(int v)
{
    int min_cost = 0;
	cout<<"MST Edges\tWeight\n";
	for (int i = 1; i < v; i++){
        cout<<parent[i]<<" -> "<<i<<"\t\t"<<graph[i][parent[i]]<<" \n";
        min_cost += graph[i][parent[i]];
    }
		
    cout<<"Minimum path cost: "<<min_cost<<endl;
    return;
}

int main()
{   
    freopen("prim.txt", "r", stdin);
    int v, e; 
    cin>>v>>e;

    // initialize all 0
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            graph[i][j]=0;
        }
    }

    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    
	MST_prim(v);
    printMST(v);

	return 0;
}


// A C++ program for Bellman-Ford's single source 
// shortest path algorithm. 
#include <bits/stdc++.h> 
using namespace std; 

void BellmanFord(vector<vector<int> > &graph, int V, int E, 
				int src) 
{ 
	int dis[V]; 
	for (int i = 0; i < V; i++) 
		dis[i] = INT_MAX; 

	dis[src] = 0; 

	for (int i = 0; i < V - 1; i++) { 

		for (int j = 0; j < E; j++) { 
			if (dis[graph[j][0]] + graph[j][2] < 
							dis[graph[j][1]]) 
				dis[graph[j][1]] = 
				dis[graph[j][0]] + graph[j][2]; 
		} 
	} 
	cout<<"*************************************************************************************************************************************************"<<endl;
	for (int i = 0; i < E; i++) { 
		int x = graph[i][0]; 
		int y = graph[i][1]; 
		int weight = graph[i][2]; 
		if (dis[x] != INT_MAX && 
				dis[x] + weight < dis[y]) 
			cout << "Graph contains negative"
					" weight cycle"
				<< endl; 
	} 

	cout << "Vertex Distance from Source" << endl; 
	for (int i = 0; i < V; i++) 
		cout << i << "\t\t" << dis[i] << endl; ;
} 

int main() 
{ 
	int V,E;
	cin>>V>>E;

	vector<vector<int> > v;
	for(int i=0;i<E;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		vector<int> temp;
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);
		v.push_back(temp);
	}
	BellmanFord(v, V, E, 0); 
	return 0; 
} 


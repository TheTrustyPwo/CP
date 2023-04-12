#include <bits/stdc++.h>

using namespace std;

int main() {
	// V - Vertexes, E - Edges
	int V, E, A, B, W, g[10][10];
	cin >> V >> E;
	memset(g, -1, sizeof(g));
	
	/*
	for (int i = 0; i < V; i++) {
		fill(g[i], g[i] + V, -1);
		for(int j = 0; j < V; j++)
			g[i][j] = -1;
	}
	*/
	
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> W;
		g[A][B] = W;
		g[B][A] = W;
	}
	
	for (int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++)
			cout << g[i][j] << " ";
		cout << endl;
	}
}

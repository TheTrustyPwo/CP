#include <bits/stdc++.h>

using namespace std;

int V, E, start, A, B;
bool visited[10];
vector<int> g[10];

void dfs(int cur) {
	cout << cur << " ";
    for (const int &n : g[cur]) {
        if (!visited[n]) {
            visited[n] = true;
            dfs(n);
        }
    }
}


int main() {
	cin >> V >> E >> start;
	
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}
	
	visited[start] = true;
	dfs(start);
}

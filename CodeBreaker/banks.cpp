#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

int n, m, in[MAXN], out[MAXN];
vector<pair<int, int>> edges;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b
		edges.push_back(make_pair(a, b));
		out[a]++, in[b]++;
	}
	
	if (n == 2) {
		if (in[1] == out[1] && in[2] == out[2])
	} else if (n == 3) {
		for (int i = 1; i <= 3; i++) 
	}
}

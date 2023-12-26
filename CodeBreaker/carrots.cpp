#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, cost = 0;
priority_queue<pair<int, pair<int, int>>> pq;

int f(int x, int y) {
	int m = x % y;
	return (y - m) * (x / y) * (x / y) + m * ((x / y) + 1) * ((x / y) + 1);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cost += x * x;
		pq.push(make_pair(f(x, 1) - f(x, 2), make_pair(x, 2)));
	}
	
	for (int i = 0; i < k - n; i++) {
		cost -= pq.top().first;
		int a = pq.top().second.first, b = pq.top().second.second; pq.pop();
		pq.push(make_pair(f(a, b) - f(a, b + 1), make_pair(a, b + 1)));
	}
	
	cout << cost;
}

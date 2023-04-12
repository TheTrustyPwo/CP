#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> deletions;
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++)
		if ((a[i - 1] & 1) == (i & 1)) pq.push(i - 1);
	
	int last = n - 1;
	while (!pq.empty()) {
		int v = pq.top(); pq.pop();
		deletions.push_back(a[v]);
		for (int i = last; i > v; i--) deletions.push_back(a[i]);
		last = v - 1;
	}
	
	cout << deletions.size() << endl;
	for (int x : deletions) cout << x << ' ';
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n], b[n]; for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		while (!pq.empty()) {
			int h = pq.top().first, k = pq.top().second;
			if (a[i] > h) {
				pq.pop();
				b[k] = i + 1;
			} else break;
		}
		pq.push(make_pair(a[i], i));
	}
	while (!pq.empty()) {
		int k = pq.top().second;
		pq.pop();
		b[k] = 0;
	}
	for (int i = 0; i < n; i++) cout << b[i] << ' ';
}

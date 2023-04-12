#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dsu, power;

int find(int n) {
	if (dsu[n] == n) return n;
	return dsu[n] = find(dsu[n]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) {
		cout << -1 << endl;
		return;
	} else if (power[a] < power[b]) swap(a, b);
	dsu[b] = a;
	cout << a + 1 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	dsu.resize(n); power.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> power[i];
		dsu[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		merge(a, b);
	}
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a, b; 

bool cmp(const pair<pair<int, int>, int> &x, const pair<pair<int, int>, int> &y) {
	int p = abs(x.first.first - a) + abs(x.first.second - b), q = abs(y.first.first - a) + abs(y.first.second - b);
	if (p == q) return x.second < y.second;
	return p < q;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> a >> b;
	pair<pair<int, int>, int> p[n];
	for (int i = 0; i < n; i++) cin >> p[i].first.first >> p[i].first.second, p[i].second = i + 1;
	sort(p, p + n, &cmp);
	for (int i = 0; i < n; i++) cout << p[i].second << ' ';
}

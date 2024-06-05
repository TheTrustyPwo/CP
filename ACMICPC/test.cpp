#include <bits/stdc++.h>
#include <art.h>
using namespace std;
typedef long long ll;

void solve(int N) {
	pair<int, int> a[N];
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) v[i] = i + 1;
	
	for (int i = 0; i < N; i++) {
		int u = publish(v);
		a[i] = {u, i + 1};
	}
	
	int tmp = a[0].first;
	for (int i = 0; i < N - 1; i++)
		a[i].first = a[i + 1].first - a[i].first;
	a[N - 1].first = tmp - a[N - 1].first;
	
	sort(a, a + N);
	vector<int> ans;
	for (int i = N - 1; i >= 0; i--) ans.push_back(a[i].second);
	answer(ans);
}

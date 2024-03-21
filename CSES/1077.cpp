#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	multiset<int> st1, st2; int s1 = 0, s2 = 0;
	for (int i = 0; i < k; i++) st1.insert(a[i]), s1 += a[i];
	while (st1.size() - 1 > st2.size()) {
		int v = *--st1.end();
		s1 -= v; s2 += v;
		st2.insert(v);
		st1.erase(--st1.end());
	}
	
	int v = *--st1.end();
	cout << (v * st1.size()) - s1 + s2 - (v * st2.size()) << ' ';

	for (int i = k; i < n; i++) {
		if (a[i - k] <= *--st1.end()) st1.erase(st1.find(a[i - k])), s1 -= a[i - k];
		else st2.erase(st2.find(a[i - k])), s2 -= a[i - k];
		
		st1.insert(a[i]), s1 += a[i];
		
		if (!st2.empty()) {
			int tmp = *st2.begin();
			st1.insert(tmp), s1 += tmp, s2 -= tmp, st2.erase(st2.begin());
		}

		while (st1.size() - 1 > st2.size()) {
			int v = *--st1.end();
			s1 -= v; s2 += v;
			st2.insert(v);
			st1.erase(--st1.end());
		}

		int v = *--st1.end();
		cout << (v * st1.size()) - s1 + s2 - (v * st2.size()) << ' ';
	}
}

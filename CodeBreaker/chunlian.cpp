#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, c, k; cin >> n >> c >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	multiset<int> ms, ms2;
	for (int i = 0; i <= k; i++) ms.insert(a[i]);
	
	int mx = 0;
	auto it = --ms.end();
	for (int i = 0; i < c; i++) {
		int v = *it;
		mx += v;
		ms.erase(it--);
		ms2.insert(v);
	}
	
	int sum = mx;
	
	for (int i = 0; i < n - k - 1; i++) {
		if (ms2.find(a[i]) != ms2.end()) {
			sum -= a[i];
			ms2.erase(ms2.find(a[i]));
		} else ms.erase(ms.find(a[i]));
		ms.insert(a[i + k + 1]);
		
		if ((int) ms2.size() < c) {
			auto itr = --ms.end();
			int v = *itr;
			sum += v;
			ms2.insert(v);
			ms.erase(itr);
		}
		
		if ((int) ms.size() > 0 && *ms2.begin() < *--ms.end()) {
			sum -= *ms2.begin();
			ms.insert(*ms2.begin());
			ms2.erase(*ms2.begin());
			ms2.insert(*--ms.end());
			sum += *--ms.end();
			ms.erase(*--ms.end());
		}
		
		mx = max(mx, sum);
	}
	
	cout << mx;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int last, cnt = 0;
	cin >> last;
	for (int i = 1; i < n; i++) {
		int a; cin >> a;
		if (last - a >= k) cnt++;
		last = a;
	}
	cout << cnt;
}

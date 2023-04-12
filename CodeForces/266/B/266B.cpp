#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t; cin >> n >> t;
	bool a[n];
	for (int i = 0; i < n; i++) {
		char ch; cin >> ch;
		a[i] = ch == 'B';
	}
	while (t--) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] && !a[i + 1]) {
				swap(a[i], a[i + 1]);
				i++;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << (a[i] ? 'B' : 'G');
}

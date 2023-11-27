#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	if (n & 1) {
		cout << "Yes\n";
		int a[n];
		for (int i = 0; i < n; i++) a[(2 * i) % n] = i;
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
	} else cout << "No";
}

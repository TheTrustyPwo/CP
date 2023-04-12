#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; fill(a, a + n, 0);
	for (int i = 0; i < n - 1; i++) {
		int e; cin >> e; e--;
		a[e]++;
	}
	for (int i = 0; i < n; i++) cout << a[i] << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int b = 0;
	for (int i = 1; i < n; i++) b = max(b, a[i] - a[i - 1]);
	cout << n - b + 1;
}

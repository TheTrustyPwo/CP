#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) { int x; cin >> x; a[x] = i; }
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}

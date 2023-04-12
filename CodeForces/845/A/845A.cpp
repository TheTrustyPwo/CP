#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n * 2]; for (int i = 0; i < n * 2; i++) cin >> a[i];
	sort(a, a + n * 2);
	if (a[n - 1] == a[n]) cout << "NO";
	else cout << "YES";
}

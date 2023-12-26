#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; string s; cin >> n >> s;
	int ans = 1;
	for (int i = 0; i < n - 1; i++) if (s[i] != s[i + 1]) ans++;
	cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, cnt = 0, ans = 0; string s; cin >> n >> s;
	for (const char ch : s) {
		if (ch == '(') cnt++;
		else cnt--;
		if (cnt == 0) ans++;
		else if (cnt < 0) break;
	}
	cout << ans;
}

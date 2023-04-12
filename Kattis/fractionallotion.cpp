#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s) {
		int n = stoi(s.substr(2));
		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			int top = n * i, bottom = i - n;
			if (top % bottom == 0) ans++;
		}
		cout << ans << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, a = 0, b = 0; string s; cin >> n >> s;
		for (int i = 0; i < n; i++)
			if (s[i] == 'Q') a++;
			else b++;
		cout << (a > b ? "No" : "Yes") << endl;
	}
}

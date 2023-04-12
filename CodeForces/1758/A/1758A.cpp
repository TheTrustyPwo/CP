#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string a, b; cin >> a;
		b = a; reverse(b.begin(), b.end());
		cout << a << b << "\n";
	}
}

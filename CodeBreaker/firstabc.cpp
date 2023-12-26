#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n; string s; cin >> s;
	bool a = 0, b = 0, c = 0; int ans = 0;
	while (!a || !b || !c) {
		a |= s[ans] == 'A', b |= s[ans] == 'B', c |= s[ans] == 'C';
		ans++;
	} cout << ans;
}

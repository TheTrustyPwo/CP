#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, k, s, e; cin >> n >> k >> s >> e;
	if ((s - e) % k == 0) cout << "Yes\n";
	else cout << "No\n";
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y, e; cin >> x >> y >> e;
	cout << max(y, x - e - e);
}

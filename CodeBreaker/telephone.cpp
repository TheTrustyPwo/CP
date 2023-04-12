#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll s, x, y; cin >> s >> x >> y;
	cout << s - x * y << ' ' << s + x * y;
}

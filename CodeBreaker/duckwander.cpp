#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int x = 0, y = 0;
	while (n--) {
		string s; int v; cin >> s >> v;
		if (s == "UP") y += v;
		else if (s == "DOWN") y -= v;
		else if (s == "RIGHT") x += v;
		else x -= v;
	}
	
	cout << x << ' ' << y;
}

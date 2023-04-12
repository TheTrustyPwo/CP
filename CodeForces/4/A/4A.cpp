#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int w; cin >> w;
	cout << (w & 1 || w == 2 ? "NO" : "YES");
}

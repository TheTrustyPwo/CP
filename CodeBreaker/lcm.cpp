#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}
}

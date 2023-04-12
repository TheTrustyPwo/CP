#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9 + 7;

ll n, t = 1, k[5005] = {0, 1};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch; cin >> ch;
		if (ch == 'f') t++;
		else for (int j = 1; j <= t; k[j] += k[j - 1] %= m, j++);
	}
	
	cout << k[t] % m;
}

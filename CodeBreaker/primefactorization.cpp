#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	
	int cnt = 0;
	while (n % 2 == 0) { n /= 2; cnt++; }
	if (cnt) cout << "2^" << cnt << "\n";
	
	for (int i = 3; i <= sqrt(n); i += 2) {
		cnt = 0;
		while (n % i == 0) { n /= i; cnt++; }
		if (cnt) cout << i << '^' << cnt << "\n";
	}
	
	if (n > 2) cout << n << "^1";
}

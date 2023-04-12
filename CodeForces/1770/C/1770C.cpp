#include <bits/stdc++.h>
using namespace std;
#define int long long

bool is_prime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

void test() {
		int n; cin >> n;
		unordered_map<int, int> m;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
			m[a[i]]++;
		}
		
		for (auto itr : m) {
			if (itr.second > 1) {
				cout << "NO\n";
				return;
			}
		}
		
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (is_prime(a[i])) count++;
		}
		
		if (count % 2 == 0) cout << "YES\n";
		else cout << "NO\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		test();
	}
}

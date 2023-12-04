#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int primes[17]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int q, k, n;
vector<ll> a, b;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> q >> k;
	
	auto it = upper_bound(primes, primes + 17, k);
	n = it - primes;
	
	a.push_back(1);
	for (int i = 0; i < n; i++) {
		for (const int w : a) {
			int cur = 1;
			while (cur <= 1e18) {
				if (w > (1e18 / cur)) break;
				b.push_back(w * cur);
				if (cur > (1e18 / primes[i])) break;
				cur *= primes[i];
			}
		}
		swap(a, b);
		b = vector<int>();
	}
	
	sort(a.begin(), a.end());

	while (q--) {
		int l, r; cin >> l >> r;
		cout << upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l) << '\n';
	}
}

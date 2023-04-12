#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, q, d = 0, cnt = 0; cin >> n >> q;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	
	while (n--) {
		ll a; cin >> a;
		pq.push(a);
	}
	
	while (q--) {
		char ch; ll a; cin >> ch >> a;
		if (ch == 'A') {
			d += a;
			while (!pq.empty() && pq.top() <= d) {
				pq.pop();
				cnt++;
			}
		} else {
			if (!pq.empty()) {
				pq.push(pq.top() + a);
				pq.pop();
			}
		}
	}
	
	cout << cnt;
}

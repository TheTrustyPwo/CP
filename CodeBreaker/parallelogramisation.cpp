#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	deque<int> dq;
	while (n--) {
		int t, x; cin >> t;
		if (t == 1) {
			cin >> x;
			dq.push_back(x);
		} else if (t == 2) dq.pop_back();
		else {
			cout << dq.front() << '\n';
			dq.pop_front();
		}
	}
}

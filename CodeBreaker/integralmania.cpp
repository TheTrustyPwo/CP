#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q; cin >> q;
	deque<int> dq; int p1 = 0, p2 = 0;
	while (q--) {
		char ch; int x; cin >> ch;
		if (ch == 'S') {
			cin >> x;
			dq.push_back(x);
			if (dq.size() & 1) p1 += x;
			else p2 += x;
		} else {
			p1 -= dq.front();
			dq.pop_front();
			swap(p1, p2);
		}
		cout << p2 << '\n';
	}
}

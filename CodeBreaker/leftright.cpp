#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q; cin >> q;
	deque<int> l; deque<int> r;
	while (q--) {
		short a; cin >> a;
		if (a == 1) {
			int b; cin >> b;
			if (!r.empty() && l.size() <= r.size()) {
				l.push_back(r.front());
				r.pop_front();
			}
			r.push_back(b);
		} else {
			l.swap(r);
			if (!r.empty() && l.size() < r.size()) {
				l.push_back(r.front());
				r.pop_front();
			}
		}
	}
	while (!l.empty()) {
		cout << l.front() << ' ';
		l.pop_front();
	}
	while (!r.empty()) {
		cout << r.front() << ' ';
		r.pop_front();
	}
}

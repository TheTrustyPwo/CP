#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	map<int, int> m;
	queue<int> q;
	while (n--) {
		int a; cin >> a;
		if (a == 1) {
			int b; cin >> b;
			q.push(b);
		} else if (a == 2) {
			int b; cin >> b;
			m[b]++;
		} else {
			while (!q.empty() && m[q.front()] > 0) {
				m[q.front()]--;
				q.pop();
			}
			cout << q.front() << ' ';
			q.pop();
		}
	}
}

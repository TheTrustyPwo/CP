#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		dq.push_back(a);
	}
	
	int x = 0, y = 0; bool turn = true;
	while (!dq.empty()) {
		int p;
		if (dq.front() > dq.back()) {
			p = dq.front();
			dq.pop_front();
		} else {
			p = dq.back();
			dq.pop_back();
		}
		
		if (turn) x += p;
		else y += p;
		
		turn = !turn;
	}
	
	cout << x - y;
}

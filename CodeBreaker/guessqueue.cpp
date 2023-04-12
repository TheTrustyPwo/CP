#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> x[n];
	for (int i = 0; i < n; i++) cin >> x[i].first >> x[i].second;
	bool a = true, b = true, c = true;
	
	queue<int> q;
	for (const auto p : x) {
		if (p.first == 1) q.push(p.second);
		else if (q.front() != p.second) { a = false; break; }
		else q.pop();
	}
	
	priority_queue<int> pq;
	for (const auto p : x) {
		if (p.first == 1) pq.push(p.second);
		else if (pq.top() != p.second) { b = false; break; }
		else pq.pop();
	}
	
	multiset<int> m; bool flag = true;
	for (const auto p : x) {
		if (p.first == 1) m.insert(p.second);
		else {
			multiset<int>::iterator it;
			if (flag) it = prev(m.end());
			else it = m.begin();
			if (*it != p.second) { c = false; break; }
			m.erase(it);
			flag = !flag;
		}
	}
	
	if (a + b + c > 1) cout << "unsure";
	else if (a) cout << "queue";
	else if (b) cout << "priority queue";
	else cout << "fickle minded priority queue";
}

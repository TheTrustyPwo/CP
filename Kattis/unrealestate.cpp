#include <bits/stdc++.h>
using namespace std;
#define int double
const int OPEN = 0, CLOSE = 1;

struct Event {
	int y, op, x1, x2;
	Event(int y, int op, int x1, int x2) : y(y), op(op), x1(x1), x2(x2) {}
};

bool cmp(Event e1, Event e2) {
	return e1.y < e2.y;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<Event> events;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		events.emplace_back(y1, OPEN, x1, x2);
		events.emplace_back(y2, CLOSE, x1, x2);
	}
	
	sort(events.begin(), events.end(), &cmp);
	
	vector<pair<int, int>> active;
	int cury = events[0].y, ans = 0.0;
	for (auto event : events) {
		int y = event.y, op = event.op, x1 = event.x1, x2 = event.x2;
		
		int query = 0, cur = -1;
		for (auto& xs: active) {
			cur = max(cur, xs.first);
			query += max(xs.second - cur, 0.0);
			cur = max(cur, xs.second);
		}
		
		ans += query * (y - cury);

		if (op == OPEN) {
			active.emplace_back(x1, x2);
			sort(active.begin(), active.end());
		} else {
			for (int i = 0; i < active.size(); i++) {
				if (active[i].first == x1 && active[i].second == x2) {
					active.erase(active.begin() + i);
					break;
				}
			}
		}

		cury = y;
	}
	
	cout << fixed << setprecision(2) << ans;
}

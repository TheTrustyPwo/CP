#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, id = 1;
pair<int, int> t[1048576];
pair<int, int> dat[200005];
queue<int> q[400005];
map<int, bool> del;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(1e9, tl);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(1e9, -1);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
	
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, pos);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	build(1, 1, 400000);
	for (int i = 1; i <= n; i++) {
		int t, x, y; cin >> t;
		if (t == 1) {
			cin >> x >> y;
			if (y == 1) {
				if (q[x + 200000].empty()) update(1, 1, 400000, x + 200000, id);
				q[x + 200000].push(id);
			} else {
				if (q[x].empty()) update(1, 1, 400000, x, id);
				q[x].push(id);
			}
			dat[id] = {x, y};
			id++;
		} else if (t == 2) {
			cin >> x;
			del[x] = 1;
		} else {
			cin >> x;
			vector<pair<int, int>> ans;
			while (x > 0) {
				pair<int, int> res = min(query(1, 1, 400000, 1, min(x, (int) 400000)), query(1, 1, 400000, 200001, 400000));
				if (res.first == 1e9) break;
				if (del[res.first]) {
					q[res.second].pop();
					int v = (q[res.second].empty() ? 1e9 : q[res.second].front());
					update(1, 1, 400000, res.second, v);
					continue;
				}
				int mn = res.first;
				if (dat[mn].second == 0) {
					x -= dat[mn].first, del[mn] = 1;
					ans.emplace_back(mn, dat[mn].first);
				} else {
					if (dat[mn].first <= x) {
						x -= dat[mn].first, del[mn] = 1;
						ans.emplace_back(mn, dat[mn].first);
					} else {
						ans.emplace_back(mn, x);
						dat[mn].first -= x;
						break;
					}
				}
			}
			
			cout << ans.size() << '\n';
			for (const auto p : ans) cout << p.first << ' ' << p.second << '\n';
		}
	}
}

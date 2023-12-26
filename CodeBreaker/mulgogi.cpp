#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int t[2097152], lazy[2097152];

void push(int v, int l, int r) {
	if (lazy[v] == -1) return;
	int len = r-l+1;
	int op = lazy[v];
	if (len > 1) {
		if (op != 3) lazy[v*2] = lazy[v*2+1] = op;
		else {
			if (lazy[v*2] == -1) lazy[v*2] = op;
			else if (lazy[v*2] < 3) lazy[v*2]^=1^2;
			else lazy[v*2] = -1;
			if (lazy[v*2+1] == -1) lazy[v*2+1] = op;
			else if (lazy[v*2+1] < 3) lazy[v*2+1]^=1^2;
			else lazy[v*2+1] = -1;
		}
	}
	if (op == 3) t[v] = len - t[v];
	else t[v] = len * (op != 2);
	lazy[v] = -1;
}
 

void update(int v, int tl, int tr, int l, int r, int op) {
	push(v, tl, tr);
    if (l > tr || tl > r)  return;
    if (l <= tl && tr <= r) {
        lazy[v] = op;
        push(v, tl, tr);
        return;
    }
	int tm = (tl + tr) / 2;
	update(v*2, tl, tm, l, r, op);
	update(v*2+1, tm+1, tr, l, r, op);
	t[v] = t[v*2] + t[v*2+1];
}

int query(int v, int l, int r) {
	push(v, l, r);
	if (t[v] == r-l+1) return -1;
	if (l == r) return l;
	int m = (l + r) / 2;
	int res = query(v*2, l, m);
	if (res != -1) return res;
	return query(v*2+1, m+1, r);
}
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; memset(lazy, -1, sizeof(lazy));
	vector<int> nums{1}; vector<array<int, 3>> a(n);
	for (auto &[op, l,  r] : a) {
		cin >> op >> l >> r;
		nums.push_back(l);
		nums.push_back(r);
		nums.push_back(r + 1);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	int sz = nums.size();
	for (auto [op, l, r] : a) {
		l = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
		r = lower_bound(nums.begin(), nums.end(), r) - nums.begin();
		update(1, 0, sz, l, r, op);
		cout << nums[query(1, 0, sz)] << '\n';
	}
}

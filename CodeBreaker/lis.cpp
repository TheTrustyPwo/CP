#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int32_t main() {
	setup();
	int n; cin >> n;
	vector<int> v(n);
	range(i, 0, n) cin >> v[i];
	vector<int> tail(n, 0);
	int length = 1;
	tail[0] = v[0];
	range(i, 1, (int) v.size()) {
		auto b = tail.begin(), e = tail.begin() + length;
		auto it = lower_bound(b, e, v[i]);
		if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
	}
	cout << length;
}

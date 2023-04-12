#include <bits/stdc++.h>
using namespace std;
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int32_t main() {
	setup();
	int n, s; cin >> n >> s;
	vector<int> v;
	int cur = 0, size = n; bool flag = false;
	while (n--) {
		int e; cin >> e;
		if (e == 1) {
			if (!flag) {
				size -= cur;
				flag = true;
			} else v.push_back(cur);
			cur = 0;
		} else cur++;
	}
	size -= cur;
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		if (s == 1) break;
		size -= v[i];
		s--;
	}
	cout << size;
}

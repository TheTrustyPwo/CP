#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int count(vector<int>&v, int l, int r) {
	int cnt = 0, m = l + (r - l) / 2;
	int left = l, right = m + 1;
	
	vector<int> temp;
	while (left <= m && right <= r) {
		if (v[left] <= v[right]) {
			temp.push_back(v[left]);
			left++;
		} else {
			temp.push_back(v[right]);
			cnt += (m - left + 1);
			right++;
		}
	}
	
	while (left <= m) { temp.push_back(v[left]); left++; }
	while (right <= r) { temp.push_back(v[right]); right++; }
	
	for (int i = l; i <= r; i++) v[i] = temp[i - l];
	return cnt;
}

int merge(vector<int> &v, int l, int r) {
	int cnt = 0;
	if (l >= r) return cnt;
	int m = l + (r - l) / 2;
	cnt += merge(v, l, m);
	cnt += merge(v, m + 1, r);
	cnt += count(v, l, r);
	return cnt;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		cout << merge(v, 0, n - 1) << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, d[100005], c[100005], mx;
priority_queue<pair<int, int>> pq1, pq2;
map<int, int> mp;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		pq1.push({c[i], i});
		pq2.push({c[i] + 2 * d[i], i});
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
        while (pq1.size() && mp[pq1.top().second]) pq1.pop();
        while (pq2.size() && mp[pq2.top().second]) pq2.pop();
        int l = pq1.top().first, r = pq2.top().first - 2 * d[mx];
        if (l > r) {
            ans += l;
            mp[pq1.top().second] = 1;
            pq1.pop();
        } else {
            ans += r;
            mp[pq2.top().second] = 1;
            mx = pq2.top().second;
            pq2.pop();
        }
        cout << ans << '\n';
	}
}

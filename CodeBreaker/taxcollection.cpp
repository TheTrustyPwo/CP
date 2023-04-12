#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[100005];
bool b[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	vector<int> v;
	for (int i = 0; i < n; i++)
		if (b[i]) v.push_back(a[i]);
		
	sort(v.begin(), v.end(), greater<int>());
	
	int idx = 0;
	for (int i = 0; i < n; i++)
		if (b[i]) a[i] = v[idx], idx++;
		
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (n - i) * a[i];
		
	cout << ans;
}

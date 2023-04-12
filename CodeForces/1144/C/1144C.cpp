#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	unordered_map<int, int> mp;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	
	for (auto it : mp)
		if (it.second > 2) return puts("NO");
		
	sort(a, a + n);
	
	vector<int> inc, dec;
	for (int i = 0; i < n; i++) {
		if (!inc.empty() && a[i] == inc.back()) dec.push_back(a[i]);
		else inc.push_back(a[i]);
	}
	
	reverse(dec.begin(), dec.end());
	
	cout << "YES\n" << inc.size() << '\n';
	for (int x : inc) cout << x << ' ';
	cout << '\n' << dec.size() << '\n';
	for (int x : dec) cout << x << ' ';
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; string s; cin >> n >> s;
	string a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		bool b = a[i].size() == s.size();
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'V' && !check(a[i][j])) b = false;
			else if (s[j] == 'C' && check(a[i][j])) b = false;
		}
		ans += b;
	}
	
	cout << ans;
}

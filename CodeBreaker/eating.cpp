#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	cin.ignore();
	unordered_set<string> ans;
	while (n--) {
		string s; getline(cin, s);
		int k = ans.size();
		ans.insert(s);
		if (k == ans.size()) cout << "NO\n";
		else cout << "YES\n";
	}
}

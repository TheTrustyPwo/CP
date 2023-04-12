#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, x; cin >> n >> k >> x;
	int cur = x;
	while (k--) {
		string s = to_string(cur);
		if (cur % 7 == 0 || s.find('7') < s.length()) cout << "UP!";
		else cout << cur;
		cout << "\n";
		cur += n;
	}
}

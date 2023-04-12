#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll a, b; cin >> a >> b;
	for (int i = a; i <= b; i++) {
		string s1 = to_string(i), s2 = s1;
		reverse(s2.begin(), s2.end());
		if (s1 == s2) cout << "Palindrome!";
		else cout << s1;
		cout << endl;
	}
}

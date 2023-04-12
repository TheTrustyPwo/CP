#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	int cnt = 0;
	for (char ch : s) {
		if (cnt == 0 && ch == 'h') cnt++;
		else if (cnt == 1 && ch == 'e') cnt++;
		else if (cnt == 2 && ch == 'l') cnt++;
		else if (cnt == 3 && ch == 'l') cnt++;
		else if (cnt == 4 && ch == 'o') cnt++;
	}
	cout << (cnt == 5 ? "YES" : "NO");
}

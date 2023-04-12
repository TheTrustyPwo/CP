#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int big[n], small[n]; bool first = true;
		for (int i = 0; i < n; i++) {
			char ch; cin >> ch;
			if (ch == '2') {
				if (first) big[i] = small[i] = 1;
				else big[i] = 0, small[i] = 2;
			} else if (ch == '1') {
				if (first) big[i] = 1, small[i] = 0, first = false;
				else big[i] = 0, small[i] = 1;
			} else big[i] = small[i] = 0;
		}
		
		for (int i = 0; i < n; i++) cout << big[i];
		cout << '\n';
		for (int i = 0; i < n; i++) cout << small[i];
		cout << '\n';
	}
}

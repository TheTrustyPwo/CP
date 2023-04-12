#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			bool a; cin >> a;
			if (!a) continue;
			cout << (abs(i - 3) + abs(j - 3));
		}
	}
}

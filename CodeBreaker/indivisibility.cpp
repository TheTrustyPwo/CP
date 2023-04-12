#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q; cin >> q;
	int cnt = 0;
	for (int i = 0; i < q; i++) {
		int x; cin >> x; bool flag = true;
		for (int i = 2; i <= 10; i++)
			if (x % i == 0) { flag = false; break; }
		cnt += flag;
	}
	cout << cnt;
}

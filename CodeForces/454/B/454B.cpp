#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int k = 0; bool flag = false;
	for (int i = 0; i < n; i++) {
		if (a[i] > a[(i + 1 >= n ? i - n + 1 : i + 1)]) {
			if (flag) return puts("-1");
			flag = true;
			k = i + 1;
		}
	}
	
	cout << n - (k == 0 ? n : k);
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	if (n == 3) {
		if (a[2] >= a[1] && a[1] - (a[2] - a[1]) >= 0) cout << 1;
		else if (a[2] >= a[0] && (a[2] - a[0]) % 2 == 0) cout << 2;
		else cout << 3;
	} else {
		vector<int> v;
		v.push_back(a[3] - a[2]);
		v.push_back(a[2] - a[1]);
		v.push_back(a[1] - a[0]);
		
		for (int diff : v) {
			int numberOfWrong = 0;
			int indexOfWrong = -1;
			int cur = a[0];
			for (int i = 1; i < n; i++) {
				cur += diff;
				if (a[i] != cur) {
					numberOfWrong++;
					indexOfWrong = i + 1;
				}
			}
			if (numberOfWrong == 1) {
				cout << indexOfWrong;
				return 0;
			}
		}
		
		cout << 1;
		return 0;
	}
}

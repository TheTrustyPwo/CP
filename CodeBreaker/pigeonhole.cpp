#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, h; cin >> n >> h;
	multiset<int> ms;
	int a[h]; fill(a, a + h, 0);
	while (n--) {
		bool b; int p; cin >> b >> p;
		int hole = p % h;
		auto it = ms.find(a[hole]);
		if (it != ms.end()) ms.erase(it);
		if (b) a[hole]++;
		else a[hole]--;
		ms.insert(a[hole]);
		cout << *(--ms.end()) << endl;
	}
}

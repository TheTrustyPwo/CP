#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int32_t main() {
	setup();
	int l, q; cin >> l;
	int a[l]; arrPut(a);
	sort(a, a + l);
	cin >> q;
	while (q--) {
		int n; cin >> n;
		int *low = lower_bound(a, a + l, n), *high = upper_bound(a, a + l, n);
		cout << "Smaller: " << low - a << ", Greater: " << a + l - high << endl;
	}
}

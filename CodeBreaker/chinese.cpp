#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	int n, x, ans = 0; cin >> n;
	int a[n], b[n]; arrPut(a); arrPut(b); cin >> x;
	sort(a, a + n); sort(b, b + n, greater<int>());
	range(i, 0, n) ans += max(0, a[i] + b[i] - x);
	cout << ans * 100;
}

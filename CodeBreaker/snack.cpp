#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	int n; cin >> n;
	int a[n];
	range(i, 0, n) {
		char c; cin >> c;
		if (c == 'M') a[i] = -2;
		else a[i] = c - '0';
	}
	range(i, 1, n)
		a[i] = max(a[i], a[i] + a[i - 1]);
	cout << max(0, *max_element(a, a + n));
}

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
	int n, sum = 0; cin >> n;
	int a[n][n];
	range(i, 0, n) range(j, 0, n) cin >> a[i][j];
	for (int i = 0, j = 0; i < n; i++, j++) sum += a[i][j];
	for (int i = 0, j = n - 1; i < n; i++, j--) sum += a[i][j];
	range(i, 0, n) sum += a[n/2][i];
	range(i, 0, n) sum += a[i][n/2];
	cout << sum - 3 * a[n/2][n/2];
}

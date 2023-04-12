#include <bits/stdc++.h>
using namespace std;
#define revrange(it, start, end) for (int it = start; it > end; it--)
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	int n; cin >> n;
	int arr[n], p[n]; arrPut(arr);
	p[n-1] = arr[n-1];
	revrange(i, n-2, -1) {
		p[i] = arr[i];
		if (p[i + 1] < 0) p[i] += p[i + 1];
	}
	cout << *min_element(p, p+n);
}

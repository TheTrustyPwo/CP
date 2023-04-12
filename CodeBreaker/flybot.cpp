#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
const int M = 1000000007;

int32_t main() {
	setup();
	int h, w; cin >> h >> w;
	int g[h][w];
	memset(g, 0, sizeof(g));
	g[0][0] = 1;
	range(i, 0, h) {
		range(j, 0, w) {
			char ch; cin >> ch;
			if (ch == 'X') {
				g[i][j] = -1;
				continue;
			}
			if (i > 0) g[i][j] = (g[i][j] + max((int) 0, g[i - 1][j])) % M;
            if (j > 0) g[i][j] = (g[i][j] + max((int) 0, g[i][j - 1])) % M;
		}
	}
	cout << g[h-1][w-1] % M;
}

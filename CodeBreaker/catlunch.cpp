#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	int n, k; cin >> n >> k;
	int a[n]; arrPut(a);
	int ans = 0, res = 0;
    priority_queue<int> q;

    range(i, 0, k) q.push(a[i]);
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        res += cur;
        ans = max(ans, res);

        if (k < n) q.push(a[k++]);
    }
    
    cout << ans;
}

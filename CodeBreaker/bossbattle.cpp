#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
pair<int, int> a[300005], qy[300005];
int ft[300005];

void update(int x, int v) {
    while (x <= 300000){
        ft[x] += v;
        x += x & -x;
    }
}

int query(int x){
    int res = 0;
    while (x){
        res += ft[x];
        x -= x & -x;
    }
    return res;
}
 
int query(int x, int y){
    return query(y) - query(x - 1);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; i++) cin >> qy[i].first >> qy[i].second;
	int idx = 0, maxh = 0, sum = 0;
	for (int x = 0; x < q; x++) {
		int A = qy[x].first, H = qy[x].second;
		if (x == 0 || A > qy[x - 1].first) {
			sum = 0;
			int it = (maxh + A - 1) / A;
			for (int i = 0; i < it; i++)
				sum += query(i * A + 1, i * A + A) * (i + 1);
		}
		while (sum < H && idx < n) {
			sum += a[idx].first * ((a[idx].second + A - 1) / A);
			update(a[idx].second, a[idx].first);
			maxh = max(maxh, a[idx].second);
			idx++;
		}
		if (sum < H) cout << -1 << '\n';
		else cout << idx << '\n';
	}
}

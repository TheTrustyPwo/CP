#include <bits/stdc++.h>
#include "gap.h"
using namespace std;
typedef long long ll;

ll a[100005];

ll findGap(int T, int N) {
	ll mn, mx;
	if (T == 1) {
		ll l = 1, r = N, rl = 1, rq = 1e18;
		while (l <= r) {
			MinMax(rl, rq, &mn, &mx);
			a[l++] = mn, a[r--] = mx;
			rl = mn + 1, rq = mx - 1;
		}
		ll ans = 0;
		for (int i = 1; i < N; i++) ans = max(ans, a[i + 1] - a[i]);
		return ans;
	} else {
		MinMax(1, (int) 1e18, &mn, &mx);
		ll bound = (mx - mn + N - 2) / (N - 1);
		ll ans = bound, x, y, l = mn, i;
		for (i = mn; i + step < mx; i += step + 1) {
			MinMax(i, i + step, &x, &y);
			if (x != -1) {
				ans = max(ans, x - l);
				l = y;
			}
		}
		MinMax(i, mx, &x, &y);
		if (x != -1) ans = max(ans, x - l);
		return ans;
	}
}

int main() {}

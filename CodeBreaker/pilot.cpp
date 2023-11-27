#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q, query[1000005], ans[1000005];
pair<int, int> a[1000005];

inline int readInt() {
	int x=0; char ch=getchar_unlocked(); bool s=1;
	while(ch<'0'||ch>'9'){if(ch=='-')s=0;ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar_unlocked();}
	return s?x:-x;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	n = readInt(), q = readInt();
	for (int i = 1; i <= n; i++) {
		int h = readInt();
		a[i] = make_pair(h, i);
	}
	
	for (int i = 0; i < q; i++) query[i] = readInt();
	
	sort(a + 1, a + n + 1, greater<pair<int, int>>());
	
	set<int> s; s.insert(0); s.insert(n + 1);
	int cur = (n * (n + 1)) / 2;
	fill(ans, ans + 1000005, -1); ans[1000004] = cur;
	for (int i = 1; i <= n; i++) {
		auto it = s.lower_bound(a[i].second);
		int l = *prev(it, 1), r = *it, diff = r - l;
		s.insert(a[i].second);
		cur -= (diff * (diff - 1)) / 2;
		cur += ((a[i].second - l) * (a[i].second - l - 1)) / 2;
		cur += ((r - a[i].second) * (r - a[i].second - 1)) / 2;
		ans[a[i].first] = cur;
	}
	
	for (int i = 1000005; i >= 0; i--) {
		if (ans[i] == -1) ans[i] = ans[i + 1];
	}
	
	for (int i = 0; i < q; i++) cout << ans[query[i] + 1] << '\n';
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n, q, ar[500005], ft[500005];
set<int> s;

void update(int x, int v){
    while (x <= n){
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
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
		update(i, ar[i]);
		if (ar[i]) s.insert(i);
	}
	
	int t, a, b, c;
	while (q--) {
		cin >> t;
		if (t == 0) {
			cin >> a >> b >> c; a++; b++;
			for (auto it = s.lower_bound(a); it != s.end() && *it <= b;) {
				update(*it, ar[*it] / c - ar[*it]);
				ar[*it] /= c;
				if (ar[*it] == 0) it = s.erase(it);
				else ++it;
			}
		} else if (t == 1) {
			cin >> a >> b; a++;
			update(a, b - ar[a]);
			ar[a] = b; s.insert(a);
		} else {
			cin >> a >> b; a++; b++;
			cout << query(a, b) << '\n';
		}
	}
}

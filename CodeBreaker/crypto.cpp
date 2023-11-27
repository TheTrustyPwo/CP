#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
const int m = 1e9 + 7;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
set_t;

int n, a[300005], f[300005];
set_t s;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++) f[i] = (i * f[i - 1]) % m;
	
	int ans = 1;
	for (int i = 0; i < n; i++) {
		ans += (s.order_of_key(a[i]) * f[n - i - 1]) % m;
		ans %= m;
		s.erase(a[i]);
	}
	
	cout << ans;
}

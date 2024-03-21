#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<
	int,
	null_type,
	greater_equal<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
o_set;

int a[3005], dp[3005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, x; cin >> n >> k >> x; x--;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = k; i <= n; i++) {
		o_set st; for (int t = i; t > i - k + 1; t--) st.insert(a[t]);
		for (int j = i - k + 1; j >= 1; j--) {
			st.insert(a[j]);
			dp[i] = max(dp[i], dp[j - 1] + *st.find_by_order(x));
		}
	}

	cout << dp[n];
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int b; cin >> b;
	
	int pre[n]; pre[0] = a[0];
	for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
	
	sort(pre + b, pre + n);
	if (pre[n - 1] == 0) { cout << 0; return 0; }
	
	int mx = 1, curr = 1;
    for (int i = b + 1; i < n; i++) {
        if (pre[i] == pre[i - 1]) curr++;
        else curr = 1;
		mx = max(mx, curr);
    }
    
    cout << mx;
}

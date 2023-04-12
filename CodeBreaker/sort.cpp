#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(string a, string b) {
    int as = a.size(), bs = b.size();
    if (as != bs) return as < bs;
    return a < b;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	string a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, &cmp);
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}

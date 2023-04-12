#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v; map<int, int> m;
    int a[n]; for (int i = 0; i < n; i++) { cin >> a[i]; m[a[i]] = i; }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int leng = m[i];
        for (int j = leng - 1; j >= i - 1; j--) {
            m[a[j]]++;
            swap(a[j], a[j + 1]);
            v.push_back(j + 1);
            cnt++;
        }
    }

    cout << cnt << '\n';
    for (const int x : v) cout << x << '\n';
}

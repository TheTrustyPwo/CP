#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll> freq;

void test_case(int test) {
    int n; cin >> n; ll a[n];
    ll maxfr = 0, current_sum = 0, ans = 0;
    bool found_wildcard = 0;
    freq.clear();
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            if (found_wildcard) ans += maxfr;
            else ans += freq[0];
            found_wildcard = 1;
            maxfr = 0, freq.clear();
        }

        current_sum += a[i];
        maxfr = max(maxfr, ++freq[current_sum]);
    }
    if (found_wildcard) ans += maxfr;
    else ans += freq[0];

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

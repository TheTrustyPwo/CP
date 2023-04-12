#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, fact = 1, res = 1; cin >> n;
    for(int i = 1; i < n; i++) {
        res *= 2;
        fact *= i;
        fact %= MOD;
        res %= MOD;
    }
    fact *= n;
    fact %= MOD;
    fact -= res;
    fact %= MOD;
    if (fact < 0) fact += MOD;
    cout << fact;
    return 0;
}

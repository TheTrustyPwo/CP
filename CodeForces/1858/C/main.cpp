#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> is_prime(100005, true);

void test_case(int test) {
    int n; cin >> n; bool b[n+1]{};
    vector<int> ans; ans.push_back(1); b[1] = 1;
    for (int i = 1; i <= (n / 2); i++) if (is_prime[i]) {
        for (int j = i; j <= n; j *= 2) {
            if (b[j]) continue;
            ans.push_back(j);
            b[j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) if (!b[i])
        for (int j = i; j <= n; j *= 2) if (!b[j]) {
            ans.push_back(j);
            b[j] = 1;
    }
    for (int u : ans) cout << u << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 100005; i++) {
        if (is_prime[i] && (ll)i * i <= 100005) {
            for (int j = i * i; j <= 100005; j += i)
                is_prime[j] = false;
        }
    }

    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

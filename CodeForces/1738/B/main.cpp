#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    int s[k]; for (int i = 0; i < k; i++) cin >> s[i];
    int unknown = n - k + 1;
    int cur = s[0] / unknown + (s[0] > 0 ? 1 : 0) * (s[0] % unknown != 0);
    for (int i = 1; i < k; i++) {
        int diff = s[i] - s[i - 1];
        if (diff < cur) {
            cout << "No\n";
            return;
        }
        cur = diff;
    }
    cout << "Yes\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

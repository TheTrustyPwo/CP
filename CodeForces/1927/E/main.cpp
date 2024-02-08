#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n];
    int cur = 1; bool b = 1;
    for (int i = 0; i < k; i++) {
        int amt = (n - i + k - 1) / k;
        cur += amt;
        if (b) for (int j = 0; j < amt; j++) a[i + j * k] = cur - (amt - j);
        else for (int j = 0; j < amt; j++) a[i + j * k] = cur - j - 1;
        b = !b;
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

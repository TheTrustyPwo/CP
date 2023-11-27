#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int q; cin >> q;
    map<int, int> st; st[0]++;
    map<int, int> cache;
    while (q--) {
        char ch; int x; cin >> ch >> x;
        if (ch == '+') st[x]++;
        else {
            while (st[cache[x]]) cache[x] += x;
            cout << cache[x] << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test_case(1);
    return 0;
}

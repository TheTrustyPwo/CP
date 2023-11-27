#include <bits/stdc++.h>
using namespace std;
#define int long long

int pre[32][200005];

void test_case(int test) {
    int n; cin >> n;
    bitset<32> a[n - 1];
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        a[i] = x;
    }

    bitset<32> b[n];
    for (int i = 0; i < 31; i++) {
        int cnt = 0;
        for (int j = 1; j < n; j++) {
            bool c = (b[j - 1].test(i) ^ a[j - 1].test(i));
            b[j].set(i, c);
            cnt += c;
        }
        if (cnt != pre[i][n - 1]) {
            b[0].set(i);
            for (int j = 1; j < n; j++) {
                bool c = (b[j - 1].test(i) ^ a[j - 1].test(i));
                b[j].set(i, c);
           }
        }
    }

    for (int i = 0; i < n; i++) cout << b[i].to_ulong() << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int j = 0; j < 32; j++) pre[j][0] = 0;
    for (int i = 1; i < 200005; i++) {
        for (int j = 0; j < 32; j++) {
            pre[j][i] = pre[j][i - 1] + ((i & (1 << j)) > 0);
        }
    }
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}

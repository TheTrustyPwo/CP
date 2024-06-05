#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int c1 = 1, c2 = n + 1; bool b1 = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int dist = i + j;
            if (dist & 1) {
                cout << c1 << ' ';
                c1++;
            } else {
                if (b1) {
                    cout << 2 * n << ' ';
                    b1 = 0;
                } else {
                    cout << c2 << ' ';
                    c2++;
                }
            }
        } cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

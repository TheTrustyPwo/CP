#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void test_case(int test) {
    int n, m, k; cin >> n >> m >> k;
    int dist = n - 1 + m - 1;
    if (k < dist || ((k - dist) & 1)) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";

    if (m == 3 && k > dist) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (j == 0) {
                    cout << "R ";
                    continue;
                }
                if (i == 1 && j == 1) {
                    cout << "B ";
                    continue;
                }
                if (j & 1ll) cout <<"R ";
                else cout << "B ";
            }
            cout << '\n';
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                if (j == m - 1) {
                    if (n & 1) {
                        if (i & 1ll) cout << "R ";
                        else cout << "B ";
                    } else {
                        if (i & 1ll) cout << "B ";
                        else cout << "R ";
                    }
                    break;
                }
                if (i & 1ll) cout << "R ";
                else cout << "B ";
            }
            cout << '\n';
        }

        return;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (i == 1 && j == 1) {
                cout << "R ";
                continue;
            }
            if (j & 1ll) cout <<"B ";
            else cout << "R ";
        }
        cout << '\n';
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                if (m % 2 == 0) {
                    if (i & 1ll) cout << "R ";
                    else cout << "B ";
                } else {
                    if (i & 1ll) cout << "B ";
                    else cout << "R ";
                }
                break;
            }
            if (i & 1ll) cout << "R ";
            else cout << "B ";
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

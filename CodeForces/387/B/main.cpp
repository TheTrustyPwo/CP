#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int b[m]; for (int i = 0; i < m; i++) cin >> b[i];
    int bestPossible = n;
    if (bestPossible > m) bestPossible = m;
    for(int i = bestPossible; i >= 0; i--) {
        bool ok = true;
        for(int j = 0; j < i; j++)
            if (a[j] > b[m - i + j]) ok = false;
        if (ok) {
            cout << n - i;
            return;
        }    
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}

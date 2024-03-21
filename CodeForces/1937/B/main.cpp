#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dir[2][2] = {{1, 0}, {0, 1}};

void test_case(int test) {
    int n; cin >> n;
    int g[2][n]; char ch;
    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) {
        cin >> ch;
        g[i][j] = ch == '1';
    }

    
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

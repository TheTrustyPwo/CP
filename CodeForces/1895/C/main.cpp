#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int, int> g[2][3];

void test_case(int test) {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (a[i] < 10 || (a[i] >= 100 && a[i] < 1000) || a[i] >= 10000) {
            odd.push_back(a[i]);
        } else even.push_back(a[i]);
    }

    int ans = 0;

    int h[5][50]; memset(h, 0, sizeof(h));
    for (int i = 0; i < n; i++) {
        int sum = a[i] % 10;
        if (a[i] < 10) { h[0][sum]++; continue; }
        else sum += (a[i] % 100) / 10;
        if (a[i] < 100) { h[1][sum]++; continue; }
        else sum += (a[i] % 1000) / 100;
        if (a[i] < 1000) { h[2][sum]++; continue; }
        else sum += (a[i] % 10000) / 1000;
        if (a[i] < 10000) { h[3][sum]++; continue; }
        else sum += (a[i] % 100000) / 10000;
        h[4][sum]++;
    }

    for (int i = 0; i < 5; i++) for (int j = 0; j < 50; j++) ans -= ((h[i][j] - 1) * h[i][j]);

    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) g[i][j].clear();
    for (int i = 0; i < odd.size(); i++) {
        if (odd[i] < 10) g[0][0][odd[i]]++;
        else if (odd[i] >= 100 && odd[i] < 1000) {
            int tmp = odd[i] % 10 + (odd[i] % 100) / 10;
            g[0][0][tmp - odd[i] / 100]++;
            g[0][1][tmp + odd[i] / 100]++;
        } else {
            int tmp = odd[i] % 10 + (odd[i] % 100) / 10 + (odd[i] % 1000) / 100;
            g[0][0][tmp - (odd[i] % 10000) / 1000 - odd[i] / 10000]++;
            g[0][1][tmp + (odd[i] % 10000) / 1000 - odd[i] / 10000]++;
            g[0][2][tmp + (odd[i] % 10000) / 1000 + odd[i] / 10000]++;
        }
    }

    for (int i = 0; i < odd.size(); i++) {
        if (odd[i] < 10) g[1][0][odd[i]]++;
        else if (odd[i] >= 100 && odd[i] < 1000) {
            int tmp = odd[i] / 100 + (odd[i] % 100) / 10;
            g[1][0][tmp - (odd[i] % 10)]++;
            g[1][1][tmp + (odd[i] % 10)]++;
        } else {
            int tmp = odd[i] / 10000 + (odd[i] % 10000) / 1000 + (odd[i] % 1000) / 100;
            g[1][0][tmp - (odd[i] % 100) / 10 - (odd[i] % 10)]++;
            g[1][1][tmp + (odd[i] % 100) / 10 - (odd[i] % 10)]++;
            g[1][2][tmp + (odd[i] % 100) / 10 + (odd[i] % 10)]++;
        }
    }

    for (int i = 0; i < odd.size(); i++) {
        int amt;
        if (odd[i] < 10) amt = g[0][0][odd[i]] + g[1][0][odd[i]];
        else if (odd[i] >= 100 && odd[i] < 1000) {
            int sum = (odd[i] % 10) + (odd[i] % 100) / 10 + odd[i] / 100;
            amt = g[0][1][sum] + g[1][1][sum];
        } else {
            int sum = (odd[i] % 10) + (odd[i] % 100) / 10 + (odd[i] % 1000) / 100 + (odd[i] % 10000) / 1000 + odd[i] / 10000;
            amt = g[0][2][sum] + g[1][2][sum];
        } ans += amt;
    }

    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) g[i][j].clear();
    for (int i = 0; i < even.size(); i++) {
        if (even[i] < 100) {
            g[0][0][even[i] % 10 + (even[i] / 10)]++;
        } else {
            int tmp = even[i] % 10 + (even[i] % 100) / 10 + (even[i] % 1000) / 100;
            g[0][0][tmp - (even[i] / 1000)]++;
            g[0][1][tmp + (even[i] / 1000)]++;
        }
    }

    for (int i = 0; i < even.size(); i++) {
        if (even[i] < 100) {
            g[1][0][even[i] % 10 + (even[i] / 10)]++;
        } else {
            int tmp = (even[i] % 1000) / 100 + (even[i] / 1000) + (even[i] % 100) / 10;
            g[1][0][tmp - even[i] % 10]++;
            g[1][1][tmp + even[i] % 10]++;
        }
    }

    for (int i = 0; i < even.size(); i++) {
        int amt;
        if (even[i] < 100) {
            int sum = even[i] % 10 + (even[i] % 100) / 10;
            amt = g[0][0][sum] + g[1][0][sum];
        } else {
            int sum = (even[i] % 10) + (even[i] % 100) / 10 + (even[i] % 1000) / 100 + even[i] / 1000;
            amt = g[0][1][sum] + g[1][1][sum];
        }
        ans += amt;
    }

    cout << ans - n << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}

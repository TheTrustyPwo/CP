#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    vector<int> cnt(30, 0);
    while (n--) {
        int t, v; cin >> t >> v;
        if (t == 1) {
            cnt[v]++;
            while (cnt[v] >= 3 && v < 29) {
                cnt[v] = 1, cnt[v + 1] += 1;
                v += 1;
            }
        } else {
            bool b = 1; vector<int> tmp(cnt);
            for (int i = 0; i <= 29; i++) {
                if ((v & (1 << i)) > 0) {
                    if (tmp[i] > 0) { tmp[i]--; continue; }
                    if (i == 0) { b = false; break; }
                    int j = i - 1;
                    for (; j > 0; j--) {
                        if (tmp[j] != 1) break;
                    }
                    if (tmp[j] >= 2) {
                        tmp[j] -= 2;
                        for (int k = i - 1; k > j; k--) tmp[k] -= 1;
                    } else { b = false; break; }
                }
            }
            cout << (b ? "YES\n" : "NO\n");
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}

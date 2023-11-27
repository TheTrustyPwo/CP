#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 998244353;
 
int factorial[200005];
 
void test_case(int test) {
    string s; cin >> s;
    int n = s.size();
    int cur = 0, mn = 0, ways = 1, cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == '0') {
            if (cur > 1) {
                mn += cur - 1;
                ways = (ways * cur) % m;
                cnt++;
            }
            cur = 0;
        }
        else cur++;
    }
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == '1') {
            if (cur > 1) {
                mn += cur - 1;
                ways = (ways * cur) % m;
                cnt++;
            }
            cur = 0;
        }
        else cur++;
    }
    ways = (ways * factorial[mn]) % m;
    cout << mn << ' ' << ways << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    factorial[0] = 1;
    for (int i = 1; i <= 200000; i++) factorial[i] = (factorial[i - 1] * i) % m;
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
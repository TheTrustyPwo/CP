#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int x = 0;
    while (n--) {
        string s; cin >> s;
        if (s[0] == '+' || s[1] == '+') x++;
        else x--;
    }
    cout << x;
    return 0;
}

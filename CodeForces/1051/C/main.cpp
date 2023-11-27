#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int t[n], a[101]{};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
        t[i] = x;
    }

    int b = 0, c = 0;
    for (int i = 1; i <= 100; i++)
        if (a[i] == 1) b++;
        else if (a[i] >= 3) c++;

    multiset<char> res[101];
    if (b % 2 == 0 || c >= 1) {
        cout << "YES\n";
        bool cnt = 0, used = 0;
        for (int i = 1; i <= 100; i++) {
            if (res[i].size()) continue;
            if (a[i] == 1) {
                res[i].insert(cnt ? 'A' : 'B');
                cnt = !cnt;
            } else if (a[i] >= 3 && (b & 1) && !used) {
                res[i].insert('A'); a[i]--;
                while (a[i]--) res[i].insert('B');
                used = 1;
            } else while (a[i]--) res[i].insert('A');
        }
        for (int i = 0; i < n; i++) {
            cout << *res[t[i]].begin();
            res[t[i]].erase(res[t[i]].begin());
        }
    } else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}

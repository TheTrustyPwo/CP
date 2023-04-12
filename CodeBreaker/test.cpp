#include <bits/stdc++.h>
using namespace std;

int t, n, k;
unordered_set<bitset<200005>> seen;

int main() {
    cin >> t;
    while (t--) {
        cin >> n; bool b = false;
        seen.clear();
        bitset<200005> or_subseq;
        for (int i = 0; i < n; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                int p;
                cin >> p;
                or_subseq[p] = 1;
            }
            if (seen.count(or_subseq)) {
                b = true;
            }
            seen.insert(or_subseq);
        }
        if (b) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, val = 0; cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        if (ch == 'L') val += i, pq.push(n - i - i - 1);
        else val += (n - i - 1), pq.push(i - n + i + 1);
    }

    for (int i = 0; i < n; i++) {
        if (pq.top() <= 0) { cout << val << ' '; continue; }
        val += pq.top(); pq.pop();
        cout << val << ' ';
    }

    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

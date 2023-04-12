#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int op = 0, sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = m; i < n; i++) {
        if (a[i] < 0) pq.push(a[i]);
        sum += a[i];
        while (sum < 0) {
            int x = pq.top(); pq.pop();
            x = -1 * x;
            sum += (2 * x);
            op++;
        }
    }
    
    if (a[m - 1] <= 0) sum = a[m - 1];
    else if (m != 1) sum = -1 * a[m - 1], op++;
    
    priority_queue<int> pq2;
    for (int i = m - 2; i >= 1; i--) {
        if (a[i] > 0) pq2.push(a[i]);
        sum += a[i];
        while (sum > 0) {
            int x = pq2.top(); pq2.pop();
            x = -1 * x;
            sum += (2 * x);
            op++;
        }
    }
    
    cout << op << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

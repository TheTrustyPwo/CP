#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, ft[400005];

int ls(int x){
    return (x & (-x));
}

void update(int l, int r, int v) {          
    r++;                                   
    for(; l <= n; l += ls(l)) ft[l] += v;   
    for(; r <= n; r += ls(r)) ft[r] -= v; 
}

int query(int p) {                          
    int sum = 0;
    for(; p; p -= ls(p)) sum += ft[p];
    return sum; 
}

void test_case(int test) {
    cin >> n; string s; cin >> s; memset(ft, 0, sizeof(ft));
    for (int i = 0; i < n; i++) {
        int num = (s[i] - '0');
        update(1, n - i, num);
    }

    vector<int> v; int carry = 0;
    for (int i = 1; i <= n; i++) {
        int res = query(i) + carry;
        v.push_back(res % 10);
        carry = res / 10;
    }

    v.push_back(carry); bool b = false;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] != 0) b = true;
        if (b) cout << v[i];
    }
    
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

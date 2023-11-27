#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> is_prime(1005, true);
vector<int> primes;

void test_case(int test) {
    int n, q; cin >> n >> q;
    map<int, int> fac;
    int cur = 1;
    for (const int p : primes) {
        if (n * n > p) break;
        else if (n % p == 0) {
            cur /= (fac[n] + 1);
            fac[p]++;
            cur *= (fac[n] + 1);
        }
    }
    int a = cur;
    while (q--) {
        int t, x; cin >> t;
        if (t == 1) {
            cin >> x;
            for (const int p : primes) {
                if (x * x > p) break;
                else if (x % p == 0) {
                    cur /= (fac[p] + 1);
                    fac[p]++;
                    cur *= (fac[p] + 1);
                }
            }
            if (a % c != 0) cout << "NO\n";
            else cout << "YES\n";
        } else cur = a;
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 1005; i++) {
        if (is_prime[i] && (long long)i * i <= 1005) {
            for (int j = i * i; j <= 1005; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 0; i <= 1005; i++) if (is_prime[i]) primes.push_back(i);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

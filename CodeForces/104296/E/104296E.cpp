#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    long double a[n]; for (ll i = 0; i < n; i++) cin >> a[i];
    
    cout << a[0] / (1LL << (n - 1)) << '\n';f
    
    long double p[n], s[n];
    p[0] = a[0] / (1LL << (n - 1));
    s[n - 1] = a[n - 1] / (1LL << (n - 1));
    for (ll i = 1; i < n; i++) p[i] = p[i - 1] + a[i] / (1LL << (n - i - 1));
    for (ll i = n - 2; i >= 0; i--) s[i] = s[i + 1] + a[i] / (1LL << i);
    
    cout << fixed << setprecision(7) << s[0] << ' ';
    for (ll i = 1; i < n - 1; i++)
        cout << fixed << setprecision(7) << p[i - 1] * (1LL << (n - i - 1)) + a[i] + s[i + 1] * (1LL << i) << ' ';
    cout << fixed << setprecision(7) << p[n - 1];
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    string s; cin >> s;
    ll ans = 0;
    for(ll i=0;i<s.size();i++) {
        int fr[10]{}, distinct=0, max_freq=0;

        for(ll j=i;j<s.size() && (++fr[s[j]-'0'])<=10;j++){

            max_freq=max(max_freq,fr[s[j]-'0']);
            if(fr[s[j]-'0']==1) distinct++;

            if(distinct>=max_freq) ans++;
        }
    }
    cout<<ans<<'\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}

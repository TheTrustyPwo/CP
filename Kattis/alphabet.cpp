#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	vector<char> v;
	
    for (char ch : s) {
        auto pile = lower_bound(v.begin(), v.end(), ch);
        if (pile == v.end()) {
            v.push_back(ch);
        } else {
            *pile = ch;
        }
    }
    
    int length = v.size();
    cout << 26 - length;
}

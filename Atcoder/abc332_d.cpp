#include <bits/stdc++.h>
using namespace std;
#define int long long

int inversions(vector<int> &arr) { 
    multiset<int> set1; 
    set1.insert(arr[0]); 
    int invcount = 0;
    multiset<int>::iterator itset1;
    for (int i=1; i<arr.size(); i++) { 
        set1.insert(arr[i]); 
        itset1 = set1.upper_bound(arr[i]); 
        invcount += distance(itset1, set1.end()); 
    } 
    return invcount; 
} 

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	set<int> a[6], b[6], c[6], d[6];
	multiset<int> aa, bb;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			a[i].insert(x);
			c[j].insert(x);
			aa.insert(x);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			b[i].insert(x);
			d[j].insert(x);
			bb.insert(x);
		}
	}
	
	if (aa != bb) { cout << -1; return 0; }
	
	bool b1 = true; bool used1[6]{}; vector<int> v1;
	for (int i = 0; i < n; i++) {
		bool bb = false;
		for (int j = 0; j < n; j++) {
			if (!used1[j] && b[i] == a[j]) {
				v1.push_back(j);
				used1[j] = 1;
				bb = true;
				break;
			}
		}
		if (!bb) { b1 = 0; break; }
	}
	
	bool b2 = true; bool used2[6]{}; vector<int> v2;
	for (int i = 0; i < m; i++) {
		bool bb = false;
		for (int j = 0; j < m; j++) {
			if (!used2[j] && d[i] == c[j]) {
				v2.push_back(j);
				used2[j] = 1;
				bb = true;
				break;
			}
		}
		if (!bb) { b2 = 0; break; }
	}
	
	if (!b1 || !b2) cout << -1;
	else cout << inversions(v1) + inversions(v2);
}

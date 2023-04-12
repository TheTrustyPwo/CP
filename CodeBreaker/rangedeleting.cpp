#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x;
int a[5000005];
vector<int> pos[5000005];
int pre[5000005];

int main() {
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		pos[a[i]].push_back(i);	
	}
	
	pre[0] = a[0];
	for (int i = 0; i < n; i++) pre[i] = max(pre[i-1], a[i]);
	
	int p = 1;
	int lst = n + 5;
	for(int i = x; i > 0; i--){
		if (pos[i].empty()) {
		    p = i;
		    continue;
		}
		if (pos[i].back() > lst) break;
		p = i;
		lst = pos[i][0];
	}	

	long long res = 0;
	lst = -1;
	for(int l = 1; l <= x; l++){
		int r = max(l, p - 1);
		if (lst != -1) r = max(r, pre[lst]);
		res += x - r + 1;
		if (!pos[l].empty()){
    		if(pos[l][0] < lst) break;
    		lst = pos[l].back();
		}
	}	

	cout << res << endl;
}

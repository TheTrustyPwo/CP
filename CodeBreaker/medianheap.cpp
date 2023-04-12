#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> rpq;
	priority_queue<int> lpq;
	while (n--) {
		string s; cin >> s;
		if (s == "PUSH") {
			int a; cin >> a;
			if (lpq.empty()) lpq.push(a);
			else if (a < lpq.top()) lpq.push(a);
			else rpq.push(a);
		} else {
			if (lpq.size() >= rpq.size()) lpq.pop();
			else rpq.pop();
		}
		
		if (lpq.size() > rpq.size() + 1) {
			rpq.push(lpq.top());
			lpq.pop();
		} else if (rpq.size() > lpq.size() + 1) {
			lpq.push(rpq.top());
			rpq.pop();
		}
	}
	
	while (!lpq.empty()) {
		rpq.push(lpq.top());
		lpq.pop();
	}
	
	while (!rpq.empty()) {
		cout << rpq.top() << ' ';
		rpq.pop();
	}
}

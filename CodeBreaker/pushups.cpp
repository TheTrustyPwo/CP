#include <bits/stdc++.h>
using namespace std;

int divsum[1000005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	
	for (int i = 1; i <= 1000000; i++)
		for (int j = i; j <= 1000000; j += i)
			divsum[j] += i;
	
	for (int i = 2; i <= 1000000; i++)
		divsum[i] = max(divsum[i - 1], divsum[i]);
	
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		cout << to_string(divsum[a]) + "\n";
	}
}

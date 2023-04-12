#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int n, a[100005], dp[5][100005];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		dp[0][i] = 1;
	}

	for (int l = 1; l < 5; l++) {
		for (int i = l; i < n; i++) {
			dp[l][i] = 0;
			for (int j = l - 1; j < i; j++) {
				if (a[j] < a[i]) {
					dp[l][i] = (dp[l][i] + dp[l - 1][j]) % mod;
				}
			}
		}
	}

	for (int i = 4; i < n; i++) {
		sum = (sum + dp[4][i]) % mod;
	}
	
	cout << sum;
}

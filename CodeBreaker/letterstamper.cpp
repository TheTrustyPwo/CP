#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int dp[305][305][27];

int solve(int start, int end, int top) {
	if (start > end) return 0;
	if (dp[start][end][top] != -1) return dp[start][end][top];
	if (top == s[start] - 'A'){
		dp[start][end][top] = solve(start + 1, end, top);
		return dp[start][end][top];
	} else {
		int mn = 1e9;
		for (int k = start; k <= end; k++)
			mn = min(mn, solve(start + 1, k, s[start] - 'A') + solve(k + 1, end, top) + 1);
		dp[start][end][top] = mn;
		return dp[start][end][top];
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, s.size() - 1, -1) * 2 + s.size();
}

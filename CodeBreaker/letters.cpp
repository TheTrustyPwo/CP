#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; getline(cin, s);
	int l = s.length();
	string w = "abcdefghijklmnopqrstuvwxyz";
	int dp[l + 1][27];
	for (int i = 0; i <= 26; i++) dp[0][i] = 0;
	for (int i = 0; i <= l; i++) dp[i][0] = 1;
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= 26; j++)
			dp[i][j] = (tolower(s[i - 1]) == w[j - 1] ? dp[i - 1][j - 1] : 0) + dp[i - 1][j];
	cout << dp[l][26];
}

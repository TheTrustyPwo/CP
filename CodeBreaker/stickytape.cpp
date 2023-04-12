#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

int n, m;
int l[N];
int dp[N];

int main() {
cin >> n >> m;
for (int i = 1; i <= m; i++) {
cin >> l[i];
}
sort(l + 1, l + m + 1);
reverse(l + 1, l + m + 1);
memset(dp, 0x3f, sizeof(dp));
dp[0] = 0;
for (int i = 1; i <= m; i++) {
for (int j = l[i]; j <= n; j++) {
dp[j] = min(dp[j], dp[j - l[i]] + l[i]);
}
}
cout << dp[n] << endl;
return 0;
}

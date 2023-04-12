#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[20][20][2];

// count[i][j][k] is the number of numbers in the range [A, B] that have
// at least i digits, the jth digit (from the left) is k, and the digits
// to the right of the jth digit are all equal to 9.
int count(long long A, long long B, int i, int j, int k) {
  if (dp[i][j][k] != -1) {
    return dp[i][j][k];
  }
  if (i == 0) {
    return dp[i][j][k] = (k == 1);
  }
  int ans = 0;
  int end = k ? 9 : (int) (B / pow(10, i - 1)) % 10;
  for (int d = 0; d <= end; d++) {
    ans = (ans + count(A, B, i - 1, j - (d != 0), k && (d == end))) % MOD;
  }
  return dp[i][j][k] = ans;
}

int main() {
  memset(dp, -1, sizeof(dp));
  long long A, B;
  cin >> A >> B;
  for (int i = 0; i <= 9; i++) {
    cout << count(A, B, 18, 18, 1) - count(A, B, 18, 18, 0) + count(A, B, 18, i, 0) << endl;
  }
  return 0;
}

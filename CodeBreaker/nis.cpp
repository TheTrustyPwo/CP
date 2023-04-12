#include <bits/stdc++.h>
using namespace std;

// define modulo
const int MOD = 1e9 + 7;

// Fenwick tree data structure
struct FenwickTree {
  // vector to store the tree data
  vector<int> tree;

  // constructor
  FenwickTree(int n) : tree(n + 1) {}

  // function to update a value in the tree
  void update(int i, int val) {
    for (; i < tree.size(); i += i & -i) {
      tree[i] = (tree[i] + val) % MOD;
    }
  }

  // function to query a prefix sum
  int query(int i) {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
      sum = (sum + tree[i]) % MOD;
    }
    return sum;
  }
};

int main() {
  // read the input
  int N;
  cin >> N;
  
  int dp[N];

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  // initialize an empty Fenwick tree
  FenwickTree ft(N);

  // initialize the answer to 0
  int ans = 0;

  // iterate over all indices i in the array
  for (int i = 0; i < N; i++) {

    // update the value of dp[i] using the Fenwick tree
    dp[i] = ft.query(A[i]);

    // add dp[i] to the answer
    ans = (ans + dp[i]) % MOD;

    // update the Fenwick tree with the new value of dp[i]
    ft.update(A[i], dp[i]);
  }

  // print the final answer
  cout << ans << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	int n; cin >> n;
	map<char, int> m;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	range(i, 0, n) {
		char c; cin >> c;
		m[c]++;
	}
	range(i, 0, alphabet.size()) cout << alphabet[i] << " " << m[alphabet[i]] << endl;
}

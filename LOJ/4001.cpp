#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int d[3005][26], suf[3005];
string s;

int cmp(int a, int b) {
	for (int i = 25; i >= 0; i--) {
		if (d[a][i] < d[b][i]) return a;
		if (d[a][i] > d[b][i]) return b;
	}
	return a;
}

bool cmp2(int a, int b) {
	int t1 = -1, t2 = -1, t3 = -1, t4 = -1;
	for (int i = 25; i >= 0; i--) {
		if (d[a][i] == 0) continue;
		if (t1 == -1) t1 = i;
		t2 = i;
	}
	for (int i = 0; i < 26; i++) {
		if (d[b][i] == 0) continue;
		if (t3 == -1) t3 = i;
		t4 = i;
	}
	if (t3 < t1) return 1;
	if (t1 == t3) return t4 < t2;
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) d[i][s[j] - 'a']++;
	}
	
	suf[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) suf[i] = cmp(suf[i + 1], i);
	
	int p = 0;
	for (int i = 0; i < n; i++) {
		bool res = 1;
		if (i < n - 1) res &= cmp2(suf[i + 1], i);
		if (i > 0) res &= cmp2(p, i), p = cmp(p, i);
		cout << res;
	}
}

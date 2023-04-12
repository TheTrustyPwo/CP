#include <bits/stdc++.h>
using namespace std;
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int32_t main() {
	setup();
	int n;
	pair<int, int> a, b, c;
	cin >> n >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
	if ((b.first > a.first && c.first < a.first) || (b.first < a.first && c.first > a.first) || (b.second > a.second && c.second < a.second) || (b.second < a.second && c.second > a.second))
		cout << "NO";
	else
		cout << "YES";
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, c; cin >> t >> c;
	unordered_map<int, int> mp[3];
	for (int i = 0; i < t; i++) {
		int x; cin >> x;
		mp[0][x] = 1;
	}
	
	string s; cin >> s; 
	pair<int, int> start[c + 1];
	start[0] = {0, 0}; // pos, score
	for (int i = 1; i <= c; i++) {
		int pos = start[i - 1].first + (s[i - 1] == 'R') - (s[i - 1] == 'L');
		int score = start[i - 1].second;
		if (s[i - 1] == 'F' && mp[0][pos]) {
			mp[2][pos] = i;
			if (mp[1].find(pos) == mp[1].end()) {
				mp[1][pos] = i;
				score++;
			}
		}
		start[i] = {pos, score};
	}
	
	// for (int i = 1; i <= c; i++) cout << start[i].first << ' ' << start[i].second << '\n';
	
	pair<int, int> end[5][c + 2];
	for (int i = 0; i < 5; i++) {
		end[i][c + 1] = {0, 0};
		int pos = start[c].first + i - 2;
		end[i][c] = {pos, (s[c - 1] == 'F' && mp[1][pos] == c)};
	}
	
	for (int k = 0; k < 5; k++) for (int i = c - 1; i > 0; i--) {
		int pos = end[k][i + 1].first + (s[i - 1] == 'L') - (s[i - 1] == 'R');
		int score = end[k][i + 1].second + (s[i - 1] == 'F' && mp[1][pos] >= i);
		end[k][i] = {pos, score};
	}
	
	// for (int k = 0; k < 5; k++){for (int i = 1; i <= c; i++) cout << end[k][i].second << ' '; cout <<'\n';}
	int ans = 0;
	for (int i = 1; i <= c; i++) {
		int tmp = (s[i - 1] == 'L' ? -1 : (s[i - 1] == 'R' ? 1 : 0));
		for (int j = -1; j <= 1; j++) {
			int change = j - tmp + 2, pos = start[i - 1].first;
			int res = start[i - 1].second;
			bool bl = mp[0][pos] && (mp[1][pos] >= i || mp[1][pos] == 0) && (mp[2][pos] <= i);
			//if (bl) cout << i << ' ' << res << '\n';
			if (j == 0 && bl) res += end[change][i + 1].second + 1;
			else if (j != 0) res += end[change][i].second;
			ans = max(ans, res);
		}
		
	}
	
	cout << ans;
}

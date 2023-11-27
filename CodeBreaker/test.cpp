#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, t, r; cin >> n >> k >> t >> r;
    double abc[r][k][t][n]; int bcd[n][r][k][n];
    for (int i = 0; i < r; i++) for (int j = 0; j < k; j++) for (int a = 0; a < t; a++) for (int b = 0; b < n; b++) cin >> abc[i][j][a][b];
    for (int i = 0; i < n; i++) for (int j = 0; j < r; j++) for (int a = 0; a < k; a++) for (int b = 0; b < n; b++) cin >> bcd[i][j][a][b];
    
    int frameCount; cin >> frameCount;
    int frames[frameCount][5];
    for (int i = 0; i < frameCount; i++) for (int j = 0; j < 5; j++) cin >> frames[i][j];
    
    double mx = min(r, r * k * t);
    
    vector<pair<int, bool>> events[t + 100];
    for (int i = 0; i < frameCount; i++) {
		events[frames[i][3]].push_back(make_pair(frames[i][0], 1));
		events[frames[i][3] + frames[i][4]].push_back(make_pair(frames[i][0], 0));
	}
	
    int sum = 0, uses[n]; fill(uses, uses + n, 0);
    
    for (int a = 0; a < t; a++) {
		for (const pair<int, int> p : events[a]) {
			if (p.second) {
				uses[frames[p.first][2]] += frames[p.first][1];
				sum += frames[p.first][1];
			} else {
				uses[frames[p.first][2]] -= frames[p.first][1];
				sum -= frames[p.first][1];
			}
		}
		
		for (int i = 0; i < r; i++) for (int j = 0; j < k; j++) {
			for (int i = 0; i < n; i++) cout << ((double) uses[i] / (double) max(sum, 1)) * mx << ' ';
			cout << '\n';
		}
    }
}

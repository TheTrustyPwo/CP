#include <bits/stdc++.h>
using namespace std;


int dir[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

int main() {
	int N, T, A, B;
	pair<int, int> K, P;
	bool board[51][51]{}, visited[51][51]{};
	queue<pair<pair<int, int>, int>> q;
	
	cin >> N >> K.first >> K.second >> P.first >> P.second >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		board[A][B] = true;
	}
	
	q.push(make_pair(K, 0));
	visited[K.first][K.second] = true;
	
	while (!q.empty()) {
		int xx = q.front().first.first, yy = q.front().first.second, t = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			if (visited[nx][ny] || board[nx][ny]) continue;
			q.push(make_pair(make_pair(nx, ny), t + 1));
			visited[nx][ny] = true;
			if (nx == P.first && ny == P.second) {
				cout << t + 1;
				return 0;
			}
		}
	}
	
	cout << -1;
}

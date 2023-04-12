#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, k;
	cin >> m >> k;
	deque<int> cards;
	for (int i = 0; i < m; i++)
		cards.push_back(i);
	string moves;
	cin >> moves;
	for (char c : moves) {
		if (c == 'A') {
			cards.push_back(cards[0]);
			cards.pop_front();
		} else if (c == 'B') {
			cards.push_back(cards[1]);
			cards.erase(cards.begin() + 1);
		}
	}
	cout << cards[k - 1] << " " << cards[k] << " " << cards[k + 1];
}

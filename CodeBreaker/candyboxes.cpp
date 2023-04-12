#include <iostream>
#include <unordered_map>
#define int long long
using namespace std;

const int N = 500005;

int n, m;

struct Box {
	int parent, size, deliciousness;
};

unordered_map<int, Box> boxes;

int find(int x) {
	if (boxes[x].parent == x) return x;
	return boxes[x].parent = find(boxes[x].parent);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	if (px == py) return;
	boxes[py].size += boxes[px].size;
	boxes[py].deliciousness += boxes[px].deliciousness;
	boxes[px].parent = py;
}

void move(int x, int y) {
	int px = find(x), py = find(y);
	if (px == py) return;
	boxes[px].size--;
	boxes[px].deliciousness -= x;
	boxes[py].size++;
	boxes[py].deliciousness += x;
	boxes[x].parent = py;
}

int32_t main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		Box box, par;
		par.parent = i + N, par.size = 1, par.deliciousness = i;
		box.parent = i + N, box.size = 1, box.deliciousness = i;
		boxes[i + N] = par;
		boxes[i] = box;
	}

	while (m--) {
		int t; cin >> t;

		if (t == 1) {
			int p, q; cin >> p >> q;
			merge(p, q);
		} else if (t == 2) {
			int p, q; cin >> p >> q;
			move(p, q);
		} else {
			int p; cin >> p;
			int root = find(p);
			cout << boxes[root].size << " " << boxes[root].deliciousness << "\n";
		}
	}
}

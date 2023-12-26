#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    int left, right;
    int sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    void add(int k, int x) {
        extend();
        sum += x;
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    int get_sum(int lq, int rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
}  *v;
char ch;
int n, q, x, y, a[200005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	v = new Vertex(0, 1e9 + 5);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v->add(a[i], 1);
	}

	while (q--) {
		cin >> ch >> x >> y;
		if (ch == '?') {
			int res = v->get_sum(x, y + 1);
			cout << res << '\n';
		} else {
			if (a[x] != y) {
				v->add(a[x], -1);
				v->add(y, 1);
				a[x] = y;
			}
		}
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9 + 7;

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
        sum += x; sum %= m;
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
        return (left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq)) % m;
    }
};

void normalize(vector<int> &v) {
	vector<int> aux = v;
	sort(aux.begin(), aux.end());
	aux.erase(unique(aux.begin(), aux.end()), aux.end());
	for(size_t i = 0; i < v.size(); i++)
		v[i] = lower_bound(aux.begin(), aux.end(), v[i]) - aux.begin() + 1;
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n; vector<int> a(n), dp(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	normalize(a);
	
	Vertex *v = new Vertex(0, 1e6);
	
	dp[0] = 1; v->add(a[0], 1);
	for (int i = 1; i < n; i++) {
		dp[i] = (1 + v->get_sum(0, a[i])) % m;
		v->add(a[i], dp[i]);
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) { ans += dp[i]; ans %= m; }
	cout << ans;
}

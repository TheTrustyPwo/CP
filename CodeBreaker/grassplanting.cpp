#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pi;
typedef pair < int, pi > pii;
typedef set < int > si;
typedef vector < pi > vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9 + 7;
#define lb lower_bound
#define ub upper_bound
#define INF 100000000000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()

int p[100100], depth[100100], heavy[100100], head[100100], pos[100100];
vi adjList[100100];
int N, Q, a, b;
char c;
int cur;

ll fw[100010], fw2[100010];
void update(ll x, ll y, ll v) { //inclusive
	for (ll tx = x; tx <= N + 10; tx += tx & (-tx)) fw[tx] += v, fw2[tx] -= v * (x - 1);
	for (ll ty = y + 1; ty <= N + 10; ty += ty & (-ty)) fw[ty] -= v, fw2[ty] += v * y;
}
ll sum(ll x) {
	ll res = 0;
	for (ll tx = x; tx; tx -= tx & (-tx)) res += fw[tx] * x + fw2[tx];
	return res;
}
ll range_sum(ll x, ll y) { //inclusive
	return sum(y) - sum(x - 1);
}

int dfs(int x) {
	int size = 1;
	int mchild = 0;
	for (auto i: adjList[x]) {
		if (i == p[x]) continue;
		p[i] = x;
		depth[i] = depth[x] + 1;
		int cs = dfs(i);
		size += cs;
		if (cs > mchild) {
			mchild = cs;
			heavy[x] = i;
		}
	}
	return size;
}

void decompose(int x, int h) {
	head[x] = h;
	pos[x] = cur++;
	if (heavy[x] != -1) decompose(heavy[x], h);
	for (auto i: adjList[x]) {
		if (i == p[x]) continue;
		if (i == heavy[x]) continue;
		decompose(i, i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	memset(heavy, -1, sizeof(heavy));
	cur = 1;
	dfs(1);
	decompose(1, 1);
	// for (int i=1;i<=N;++i)cout<<i<<' '<<pos[i]<<'\n';
	for (int i = 0; i < Q; ++i) {
		cin >> c >> a >> b;
		if (c == 'P') {
			if (depth[a] > depth[b]) swap(a, b);
			for (; head[a] != head[b]; b = p[head[b]]) {
				if (depth[head[a]] > depth[head[b]]) swap(a, b);
				update(pos[head[b]], pos[b], 1);
				// cout << "Updating " << pos[head[b]] << ' ' << pos[b] << '\n';
			}
			if (depth[a] > depth[b]) swap(a, b);
			update(pos[a] + 1, pos[b], 1);
			// cout << "Updating " << pos[a]+1 << ' ' << pos[b] << '\n';
		} else {
			int res = 0;
			if (depth[a] > depth[b]) swap(a, b);
			for (; head[a] != head[b]; b = p[head[b]]) {
				if (depth[head[a]] > depth[head[b]]) swap(a, b);
				res += range_sum(pos[head[b]], pos[b]);
				// cout<<"Querying "<<pos[head[b]]<<' '<<pos[b]<<'\n';
			}
			if (depth[a] > depth[b]) swap(a, b);
			res += range_sum(pos[a] + 1, pos[b]);
			// cout<<"Querying " << pos[a]+1<<' '<<pos[b]<<'\n';
			cout << res << '\n';
		}
	}
}

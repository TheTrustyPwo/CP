#include <iostream>
#include <vector>
#define pb push_back
typedef long long ll;
using namespace std;
const int N = 100005;

template<int SZ, bool VALS_IN_EDGES> struct HLD { 
	int N; vector<int> adj[SZ];
	int par[SZ], root[SZ], depth[SZ], sz[SZ], ti;
	int pos[SZ]; vector<int> rpos;
	void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void dfsSz(int x) { 
		sz[x] = 1; 
		for (int y : adj[x]) {
			par[y] = x; depth[y] = depth[x]+1;
			adj[y].erase(find(all(adj[y]),x)); /// remove parent from adj list
			dfsSz(y); sz[x] += sz[y];
			if (sz[y] > sz[adj[x][0]]) swap(y,adj[x][0]);
		}
	}
	void dfsHld(int x) {
		pos[x] = ti++; rpos.pb(x);
		for (int y : adj[x]) {
			root[y] = (y == adj[x][0] ? root[x] : y);
			dfsHld(y); }
	}
	void init(int _N, int R = 0) { N = _N; 
		par[R] = depth[R] = ti = 0; dfsSz(R); 
		root[R] = R; dfsHld(R); 
	}
	int lca(int x, int y) {
		for (; root[x] != root[y]; y = par[root[y]])
			if (depth[root[x]] > depth[root[y]]) swap(x,y);
		return depth[x] < depth[y] ? x : y;
	}

template<typename T, int SZ1> struct LazySeg { 
	const T ID{}; T cmb(T a, T b) { return a+b; }
	T seg[2*SZ1], lazy[2*SZ1]; 
	LazySeg() { for (int i = 0; i < 2 * SZ1; i++) seg[i] = lazy[i] = ID; }
	void push(int ind, int L, int R) { /// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) for (int i = 0; i < 2; i++) lazy[2*ind+i] += lazy[ind]; /// prop to children
		lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for (int i = 1; i < SZ1; i++) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ1-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ1-1) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};
	LazySeg<ll,SZ> tree;
	
	template <class BinaryOp>
	void processPath(int x, int y, BinaryOp op) {
		for (; root[x] != root[y]; y = par[root[y]]) {
			if (depth[root[x]] > depth[root[y]]) swap(x,y);
			op(pos[root[y]],pos[y]); }
		if (depth[x] > depth[y]) swap(x,y);
		op(pos[x]+VALS_IN_EDGES,pos[y]); 
	}
	void modifyPath(int x, int y, int v) { 
		processPath(x,y,[this,&v](int l, int r) { 
			tree.upd(l,r,v); }); }
	ll queryPath(int x, int y) { 
		ll res = 0; processPath(x,y,[this,&res](int l, int r) { 
			res += tree.query(l,r); });
		return res; }
	void modifySubtree(int x, int v) { 
		tree.upd(pos[x]+VALS_IN_EDGES,pos[x]+sz[x]-1,v); }
};

int main() {
    int n; cin >> n;
    int a[n], p[n];
    for (int i = 1; i <= n; i++) cin >> a[i];
    HLD<100005, false> hld;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        hld.ae(p[i], i);
        hld.ae(i, p[i]);
    }
    
    int q; cin >> q;
    while (q--) {
		int t, u, v, k; cin >> t;
		if (t == 1) {
			
		} else if (t == 2) {
			cin >> u >> v >> k;
			hld.modifyPath(u, v, k);
		} else if (t == 3) {
			cin >> u >> k;
			hld.modifySubtree(u, k);
		} else if (t == 4) {
			cin >> u >> v;
			cout << hld.queryPath(u, v) << "\n";
		} else if (t == 5) {
			cin >> u;
			cout << "nope" << "\n";
		}
	}
}

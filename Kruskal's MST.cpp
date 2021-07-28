#include "bits/stdc++.h"
using namespace std;
#define int          long long
#define pb           push_back
#define lld          long double
#define all(c)       c.begin(),c.end()
#define si(x)        (int)(x.size())
#define pii          pair<int,int>
#define ff           first
#define ss           second
#define FOR(x,a)     for(auto&x :a)
#define rep(i,a,b)   for(int i=a;i<b;i++)
#define repd(i,a,b)  for(int i=a;i>=b;i--)
#define mem(a,x)     memset(a,x,sizeof(a))
#define pnr(a)       FOR(i,a){cout<<i<<" ";}cout<<"\n";

#define endl '\n'
const long long inf = 1e18;
const int32_t mod = 1000000007;
const int N = 3e5 + 5;

#ifdef LOCAL
#include  "./debugger_z.cc"
#else
#define deb //
#endif

int n , m;
vector<int> gr[N];
int vis[N];

struct DSU {
	int n , components;
	vector<int> par , sz;

	DSU(int nn) {
		n = components = nn;
		par.assign(n + 5 , 0);
		sz.assign(n + 5 , 1);
		iota(all(par) , 0);
	}
	int root(int x) {
		if (x == par[x])return x;
		return par[x] = root(par[x]);
	}
	void merge(int x , int y) {
		x = root(x);
		y = root(y);
		if (x == y)return;
		if (sz[x] < sz[y])swap(x , y);
		par[y] = x;
		sz[x] += sz[y];
		sz[y] = 0;
		components--;
	}
};
int f(int n) {
	return n * (n - 1) / 2;
}

int solve() {
	vector<pair<int , pii>> store , tree;

	cin >> n >> m;
	rep(i , 0 , m) {
		int x , y , w;
		cin >> x >> y >> w;
		store.pb({w , {x , y}});
	}

	// Kruskal part
	sort(all(store));

	DSU d(n + 1);
	int cost = 0;

	for (auto &i : store) {
		if (d.root(i.ss.ff) == d.root(i.ss.ss))
			continue;
		cost += i.ff;
		tree.pb(i);
		d.merge(i.ss.ff , i.ss.ss);
	}
	reverse(all(tree));

	// kruskal ended

	DSU d2(n + 1);
	int presum = 0;
	int ans = 0;
	FOR(i , tree) {

		if (d2.root(i.ss.ff) == d2.root(i.ss.ss)) {
			presum += i.ff;
			continue;
		}
		int x = d2.root(i.ss.ff);
		int y = d2.root(i.ss.ss);

		presum += i.ff;
		ans += presum * d2.sz[x] * d2.sz[y];
		d2.merge(x , y);
	}
	cout << ans << endl;

	return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);

#ifdef LOCAL
	auto start1 = chrono::high_resolution_clock::now();
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tests = 1;
	//cin>>tests;
	for (int i = 1 ; i <= tests ; i++) {
		solve();
	}

	return 0 ;
}

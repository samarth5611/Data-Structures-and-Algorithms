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

int n , m;
vector<pii> gr[N] , mst[N];
int dis[N] , par[N] , vis[N];

int prim(int src) { // finds the cost and make MST
	for (int &i : dis)i = inf;

	set<pair<int , int>> s;
	s.insert({0 , src});
	int cost = 0;
	dis[src] = 0;

	while (!s.empty()) {
		pii x = *s.begin();
		s.erase(s.begin());

		vis[x.ss] = 1;
		cost += x.ff;

		int u = x.ss;
		int v = par[x.ss];
		int w = x.ff;

		// tree[u].pb({v , w});
		// tree[v].pb({u , w});

		for (pii &i :  gr[x.ss]) {
			if (vis[i.ff] )
				continue;
			if (dis[i.ff] > i.ss) {
				s.erase({dis[i.ff] , i.ff});
				dis[i.ff] = i.ss;
				s.insert({dis[i.ff] , i.ff});
				par[i.ff] = x.ss;
			}
		}
	}
	return cost;


}


int solve() {
	cin >> n >> m;

	for (int i = 0 ; i < m ; i++) {
		int x , y, w;
		cin >> x >> y >> w;
		gr[x].pb({y , w});
		gr[y].pb({x , w});
	}

	cout << prim(1) << endl;


	return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);

#ifdef LOCAL
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

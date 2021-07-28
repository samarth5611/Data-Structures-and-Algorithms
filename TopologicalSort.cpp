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
vector<int> gr[N];
int vis[N];

int dfs_for_cycle(int node , int par) {
	if (vis[node] == 2)
		return 0;
	if (vis[node] == 1)
		return 1;
	vis[node] = 1;
	for (int i :  gr[node]) {
		if (dfs_for_cycle(i , node))
			return 1;
	}
	vis[node] = 2;
	return 0;
}

int solve() {
	cin >> n >> m;
	rep(i , 0 , m) {
		int x , y;
		cin >> x >> y;
		gr[x].pb(y);
	}

	// finding cycle
	// mem(vis , 0);
	// rep(i , 1 , n + 1) {
	// 	if (vis[i] == 0  and dfs_for_cycle(i , -1)) {
	// 		cout << "Sandro fails." << endl;
	// 		return 0;
	// 	}
	// }

	// topotogical sorting using BFS
	vector<int> in(n + 1 , 0);
	rep(i , 1 , n + 1) {
		for (int j : gr[i])
			in[j]++;
	}

	set<int> s;
	mem(vis , 0);
	// insert all the element with zero indegree
	rep(i , 1 , n + 1) {
		if (in[i] == 0) {
			s.insert(i);
			vis[i] = 1;
			// ans.pb(i);
		}
	}
	vector<int> ans(n + 1);
	int idx = 1;
	while (si(s) > 0) {
		int fr = *s.begin();
		s.erase(s.begin());
		ans.pb(fr);
		ans[fr] = idx;
		idx++;
		for (int i : gr[fr]) {
			in[i]--; //decrese the indegrreee
			if (in[i] == 0)
				s.insert(i); //insert the element with zero indegree
		}
	}
	rep(i , 1 , n + 1)
	cout << ans[i] << " ";
	cout << endl;
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

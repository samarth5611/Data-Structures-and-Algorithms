#include "bits/stdc++.h"
using namespace std;

#define pb               push_back
#define ff               first
#define all(x)           (x).begin(),(x).end()
#define FOR(a)           for(auto& ix :a)
#define rep(i,a,b)       for(int i=a;i<b;i++)
#define int              long long
#define lld              long double
#define pii              pair<int,int>
#define endl             '\n'
#define ss               second
#define si(x)            (int)x.size()

const long long inf = 1e18;
const long long mod = 1e9 + 7;

int test_case();
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(20);

	int tests = 1;
	//cin>>tests;
	for (int tt = 1 ; tt <= tests ; tt++) {
		test_case();
	}
	return 0 ;
}
const int mxn = 3e5 + 5;

vector<int> gr[mxn];
vector<int> revgr[mxn];
int vis[mxn];
stack<int> st;
vector<int> scc_node;

int dfs1(int node)
{
	vis[node] = 1;
	FOR(gr[node])
	{
		if (vis[ix] == 0)
		{
			dfs1(ix);
		}
	}
	st.push(node);
	return 0;
}

int dfs2(int node)
{
	vis[node] = 1;
	scc_node.pb(node);
	FOR(revgr[node])
	{
		if (vis[ix] == 0)
		{
			dfs2(ix);
			cout << " " << ix << endl;
		}
	}
	return 0;
}

int test_case() {
	int n , m , s , e;
	cin >> n >> m >> s >> e;

	vector<int> fi(n + 1 , 0);
	rep(i , 1 , n + 1)
	cin >> fi[i];

	rep(i , 0 , m)
	{
		int x , y;
		cin >> x >> y;
		gr[x].pb(y);
		revgr[y].pb(x);
	}
	memset(vis , 0 , sizeof vis);

	dfs1(1);
	// while (st.empty() == 0)
	// {
	// 	cout << st.top() << endl;
	// 	st.pop();
	// }

	map< int , vector<int> > newgr;
	memset(vis , 0 , sizeof vis);
	while (st.empty() == 0)
	{
		int node = st.top();
		st.pop();
		// deb(vis[node]);
		if (vis[node] == 0)
		{
			// cout << "SCC :" << node;
			dfs2(node);
		}
		cout << endl;

	}
	pnr(scc_node);
	return 0;
}

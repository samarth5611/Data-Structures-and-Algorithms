// https://www.codechef.com/problems/TALCA



#include "bits/stdc++.h"
using namespace std;

#define endl         '\n'
#define int          long long
#define all(c)       c.begin(),c.end()

const int mod = 1e9 + 7;
const long long inf = 1e18;
const int N = 3e5 + 5;
 
int n;
vector<int> gr[N];
const int logn = 22;
int dp[N][logn] , lvl[N];


void dfs(int node , int par , int lvlcount){
	dp[node][0] = par;
	lvl[node] = lvlcount;

	for(int i = 1 ; i< logn ; i++){
		dp[node][i] = dp[dp[node][i-1]][i-1];
	}

	for(int i : gr[node]){
		if(i != par)
			dfs(i , node , lvlcount + 1);
	}
}

int get_lca(int x , int y){
    if(lvl[x] < lvl[y])swap(x , y);

    for(int i = logn-1 ; i>=0 ; i--){
    	if(lvl[dp[x][i]] >= lvl[y])
    		x = dp[x][i];
    }

    if(x == y)
    	return x;

    for(int i = logn - 1; i>=0 ; i--){
    	if(dp[x][i] != dp[y][i]){
    		x = dp[x][i];
    		y = dp[y][i];
    	}
    }

    return dp[x][0];

}

int dis(int x , int y){
	int lca = get_lca(x , y);
	int distance = lvl[x] + lvl[y] - 2*lvl[lca];
	return distance;
}


int solve(){

	cin>>n;
	for(int i = 0 ; i<n-1 ; i++){
		int x , y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1 , -1  , 1);


	int q;
	cin>>q;
	while(q--){
		int r , x , y;
		cin>>r>>x>>y;

		vector<vector<int>> p;
		p.push_back({0 , x});
		p.push_back({0 , y});
		p.push_back({0 , r});
		p.push_back({0 , get_lca(x, y)});
		p.push_back({0 , get_lca(x , r)});
		p.push_back({0 , get_lca(y , r)});

		for(int i = 0 ; i<6 ; i++){
			int cur = p[i][1];

			int tot = dis(cur , x) + dis(cur , y) + dis(cur , r);
			p[i][0] = tot;
		}

		sort(all(p));

		cout<<p[0][1]<<endl;

	}

	return 0;
}

signed main(){
	ios::sync_with_stdio(0);cout.tie(0);
	cout<<fixed<<setprecision(20);

	int t = 1;
	//cin>>t;
	for(int i = 1 ; i<=t ; i++){
		solve();
	}
	return 0;
}
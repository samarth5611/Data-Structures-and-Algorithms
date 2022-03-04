// https://atcoder.jp/contests/abc239/tasks/abc239_e 


#include "bits/stdc++.h"
using namespace std;

#define endl         '\n'
#define int          long long
#define all(c)       c.begin(),c.end()

const int mod = 1e9 + 7;
const long long inf = 1e18;
const int N = 1e5 + 5;
 
int n , q;
vector<int> gr[N];
vector<int> a;
multiset<int> currentElements;
int dp[N][21];

const int k = 20;


multiset<int> dfs(int node , int parent){
	multiset<int> cur;

	for(int nodes : gr[node]){
		if(nodes == parent)
			continue;
		multiset<int> new_set = dfs(nodes , node);
		if(new_set.size() > cur.size()){
			swap(new_set , cur);
		}

		for(int i : new_set){
			cur.insert(i);
			if(cur.size() > k)
				cur.erase(cur.begin());
		}
		new_set.clear();
	}

	cur.insert(a[node]);
	if(cur.size() > k)
		cur.erase(cur.begin());

	int idx = 1;
	for(auto i = cur.rbegin() ; i != cur.rend() ; i++){
		dp[node][idx] = *i;
		idx++;
	}
	return cur;
}

int solve(){
	cin>>n>>q;
	a.resize(n+1);
	memset(dp , 0 , sizeof dp);

	for(int i = 1 ; i<=n ; i++)
		cin>>a[i];

	for(int i = 0 ; i< n-1 ; i++){
		int x ,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1 , -1);

	// for(int i = 1 ; i<=n ; i++){
	// 	for(int j = 1 ; j<=5 ; j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	while(q--){
			int node , K;
			cin>>node>>K;
			cout<<dp[node][K]<<endl;
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
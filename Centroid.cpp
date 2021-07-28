#include "bits/stdc++.h"
using namespace std;

#define pb push_back

const int N = 1e5 + 5;
vector<int> gr[N];
int n;

vector<int> res;
vector<int> sub;

int dfs_for_centroid(int node , int par) {

	bool is_centroid = 1;

	sub[node] = 1;
	for (auto &i : gr[node]) {
		if (i == par)continue;
		dfs_for_centroid(i , node);
		sub[node] += sub[i];
		if (sub[i] > n / 2)is_centroid = 0;
	}
	if (n - sub[node] > n / 2)is_centroid = 0;
	if (is_centroid)res.pb(node);
	return 0;

}

vector<int> centroid() {
	sub.assign(n + 1 , 0);

	dfs_for_centroid(1 , -1);
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;
	for (int i = 0 ; i < n - 1 ; i++) {
		int x , y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	vector<int> centroids = centroid();

	for (int i : centroids)
		cout << i << " ";


	return 0 ;
}


/*

https://codeforces.com/blog/entry/57593

vector<int> Centroid(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}
*/
#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> gr[N];
//----------------------------------------------------------

const int logn = 22;
int up[N][logn] , lvl[N];

int dfs(int node , int par , int cnt) {
	lvl[node] = cnt;
	up[node][0] = par;

	for (int i = 1 ; i < logn ; i++) {
		up[node][i] = up[up[node][i - 1]][i - 1];
	}

	for (int i : gr[node]) {
		if (i != par)
			dfs(i , node , cnt + 1);
	}
	return 0;
}

int kth_ancestor(int x , int y) {  // finds the yth ancestor of x
	for (int i = 0 ; i < logn ; i++) {
		if ( y & (1 << i)) {
			y -= (1 << i);
			x = up[x][i];
		}
	}
	return x;
}

int get_lca(int x , int y) {
	if (lvl[x] < lvl[y]) {
		swap(x , y);
	}

	int k = lvl[x] - lvl[y];
	x = kth_ancestor(x , k);
	if (x == y) {
		return x;
	}

	for (int i = logn - 1  ; i >= 0 ; i--) {
		if (up[x][i] != up[y][i]) {
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

//-------------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	memset(up , -1 , sizeof up);
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		int sz;
		cin >> sz;
		gr[i + 1].resize(sz);
		for (int j = 0 ; j < sz ; j++)
			cin >> gr[i + 1][j];
	}

	for (int i = 1 ; i <= n ; i++) {
		for (int  &x : gr[i])
			x++;
	}

	dfs(1 , 0 , 1);

	int q;
	cin >> q;
	while (q--) {
		int x , y;
		cin >> x >> y;
		x++; y++;
		cout << get_lca(x , y) - 1 << endl;
	}
	return 0 ;
}

#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
const int logn = 21;

int n;
vector<int> gr[N];
int up[N][logn];

int dfs(int node , int par) {

	up[node][0] = par;

	for (int i = 1 ; i < logn ; i++) {
		up[c][i] = up[up[c][i - 1]][i - 1];
	}

	for (int i : gr[node]) {
		if (i != par)
			dfs(i , node);
	}
}

int lift(int x , int y) {  // finds the yth ancestor of x

	for (int i = 0 ; i < logn ; i++) {
		if ( y & (1 << i)) {
			y -= (1 << i);
			x = up[x][i];
		}
	}
	return x;
}



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

	dfs(1 , 0);



	return 0 ;
}

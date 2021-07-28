#include "bits/stdc++.h"
using namespace std;

int p[1001][1001];
void init() {
	p[0][0] = 1;
	for (int n = 1 ; n <= 1000 ; n++) {
		for (int r = 0 ; r <= n ; r++) {
			p[n][r] = p[n - 1][r - 1] + p[n - 1][r];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif

	init();


	return 0 ;
}

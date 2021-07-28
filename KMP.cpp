#include "bits/stdc++.h"
using namespace std;
#define int              long long
#define endl             '\n'
#define pb               push_back
#define si(x)            (int)((x).size())
#define all(x)           (x).begin(),(x).end()
#define FOR(ix,a)        for(auto& ix :a)
#define rep(i,a,b)       for(int i=a;i<b;i++)
const int N   = 3e5 + 5;

string sa , sb;
vector<int> pi;

int prefix_function() {
	pi[0] = 0;
	for (int i = 1 ; i < si(sb) ; i++) {
		int j = pi[i - 1];
		while (j > 0  and sb[i] != sb[j]) j = pi[j - 1];
		if (sb[i] == sb[j]) j++;
		pi[i] = j;
	}
	return 0;
}

int chk() {
	vector<int> ans;
	int i = 0 , j = 0;
	while (i < si(sa)) {
		if (sa[i] == sb[j]) {
			i++ , j ++;
		}

		if (j == si(sb)) {
			ans.pb(i - j + 1);
			j = pi[j - 1];
		}
		else if (i < si(sa)  and sb[j] != sa[i]) {
			if (j != 0)
				j = pi[j - 1];
			else
				i++;
		}
	}
	if (si(ans) == 0) {
		cout << "NOT FOUND" << endl ;
	}
	else {
		cout << si(ans) << endl;
		for (auto &i : ans)
			cout << i << " ";
		cout << endl ;
	}
	return 0;
}


int solve() {

	cin >> sa >> sb;


	pi.resize(si(sb));
	prefix_function();
	chk();
	return 0;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif

	int tests = 1;
	cin >> tests;
	for (int i = 1 ; i <= tests ; i++) {
		solve();
	}
	return 0 ;
}



#include "bits/stdc++.h"
using namespace std;
#define int           long long
#define endl          '\n'
#define pii           pair<int,int>
#define ff            first
#define ss            second
#define inf           1e18
#define pb            push_back
#define si(x)         (int)((x).size())
#define all(x)        (x).begin(),(x).end()
#define FOR(ix,a)     for(auto& ix :a)
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define pnr(x)        FOR(ix,x){cout<<ix<<" ";}cout<<"\n";

string multi (string a , string b) {
	int n = si(a);
	int m = si(b);

	vector<int> ans(n + m , 0);
	int idxa = 0;
	int idxb = 0;

	for (int i = n - 1  ; i >= 0 ; i--) {
		int x = a[i] - '0';
		int carry = 0;

		idxb = 0;
		for (int j = m - 1 ; j >= 0 ; j--) {
			int y = b[j] - '0';

			int sum = x * y + ans[idxb + idxa] + carry;

			carry = sum / 10;
			ans[idxa + idxb] = sum % 10;

			idxb++;
		}
		if (carry > 0)
			ans[idxb + idxa] += carry;

		idxa++;
	}

	int it = ans.size() - 1;
	while (it >= 0  and ans[it] == 0)
		it--;

	if (it == -1)return "0";

	string res;
	while (it >= 0)
		res += to_string(ans[it--]);

	return res;
}

int solve() {

	string a , b;
	cin >> a >> b;

	cout << multi(a , b);
	return 0;
}

signed main() {
#ifndef ONLINE_JUDGE
	auto start1 = chrono::high_resolution_clock::now();
	freopen("in.txt", "r", stdin);
#endif

	int tests = 1;
	//cin>>tests;
	for (int i = 1 ; i <= tests ; i++) {
		solve();
	}

	return 0 ;
}

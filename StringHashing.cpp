#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;
#define int long long

int power(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % mod;
		b /= 2; a = (a * a) % mod;
	}
	return ans;
}
int invmod(int num) {
	return power(num, mod - 2);
}

//  use Prime p = 31  or 29
struct Hash {

	vector<int> h , inv;
	int p , MOD , n;
	Hash() {}

	Hash(string &s, int prime, int mod) : p(prime), MOD(mod)
	{
		n = s.size();
		h.resize(n + 1, 0);
		inv.resize(n + 1 , 0);

		int cur = p;
		for (int i = 1 ; i <= n ; i++) {
			h[i] = (s[i - 1] - 'a' + 1) * cur;
			inv[i] = invmod(cur);
			h[i] %= MOD;
			cur = cur * p;
			cur %= MOD;
		}
		for (int i = 1 ; i <= n ; i++)
			h[i] += h[i - 1] , h[i] %= mod;
	}
	void print() {
		for (int i = 0 ; i <= n ; i++)
			cout << h[i] << " ";
		cout << endl;
	}
	// 1-based indexing
	int get_hash(int l , int r) {
		int res = h[r] - h[l - 1];
		if (res < 0)res += MOD;

		res *= inv[l];
		res %= MOD;
		return res;
	}
};

Hash h1;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif


	return 0 ;
}

int power(int a, int b) {
	int res = 1;
	while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; }
	return res;
}
const int mod = 1e9 + 7;


int powerM(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % mod;
		b /= 2; a = (a * a) % mod;
	} return ans;
}
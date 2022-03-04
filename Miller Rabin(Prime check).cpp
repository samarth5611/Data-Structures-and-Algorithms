// https://www.spoj.com/problems/PON/

inline int mul(int a, int b, int mod)
{
	a %= mod;
	b %= mod;
	if (mod <= 2e9) return a * b % mod;
	int res = 0;
	while (b > 0) {
		if (b % 2 == 1) res = (res + a) % mod;
		a = (a * 2) % mod;
		b /= 2;
	}
	return res % mod;
}

inline int power(int x, int n, int m)
{
	int res = 1;
	while (n) {
		if (n & 1) res = mul(res, x, m);
		x = mul(x, x, m);
		n >>= 1;
	}
	return (res % m);
}

int SPRP[7] = {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL};
bool miller_rabin(int  p, int t = 7)		//t = 7 for SPRP base
{
	//returns true if n is probably prime, else returns false.
	if (p < 4) return (p > 1);
	if (!(p & 1LL)) return false;
	int x = p - 1;
	int e = __builtin_ctzll(x);
	x >>= e;
	while (t--) {
		//ll witness = (rng() % (p-3)) + 2;	//Using random witness
		int witness = SPRP[t];
		witness = power(witness % p, x, p);
		if (witness <= 1) continue;
		for (int i = 0; i < e && witness != p - 1; i++)
			witness = mul(witness, witness, p);
		if (witness != p - 1) return false;
	}
	return true;
}

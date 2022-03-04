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

// factorizes single number in SQRT(n) complexity
vector<int> factorize(int n) {
	vector<int> mp;

	for (int i = 2 ; i * i <= n ; i++) {
		while (n % i == 0) {
			mp.push_back(i);
			n /= i;
		}
	}
	if (n > 1)mp.push_back(n);
	return mp;
}

// finds all the prime numbers in NLog(LogN)

vector<int> p;
// set<int> p;
int primes(const int N = 1e6)
{
	p.push_back(2);
	// p.insert(2);
	vector<bool> vis(N , 0);
	for (int i = 2 ; i < N ; i += 2) vis[i] = 1;
	for (int i = 3 ; i * i < N ; i += 2) {
		if (vis[i] == 0) {
			for (int j = i * i ; j < N ; j += i )
				vis[j] = 1;
		}
	}
	for (int i = 3 ; i < N ; i++)
		if (vis[i] == 0) {
			p.push_back(i);
			//p.insert(i);
		}
	return 0;
}

//  factories any number with precalculation

vector<int> spf;
void build_sieve(int n) {
	spf.resize(n);
	for (int i = 1 ; i < n ; i++)
		spf[i] = i;
	for (int i = 2 ; i < n ; i += 2)
		spf[i] = 2;
	for (int i = 3 ; i * i < n ; i++) {
		if (spf[i] == i) {
			for (int j = i * i ; j < n ; j += i) {
				if (spf[j] == j)spf[j] = i;
			}
		}
	}
}
vector<int> get_factor(int x) {
	vector<int> ret;
	while (x > 1) {
		ret.push_back(spf[x]);
		x = x / spf[x];
	} return ret;
}

// phi-function ϕ(n),counts the no of integer between 1 and n inclusive,
// which are coprime to n

// for prime number(p), ϕ(p) = p-1

// Calculates for integer in (sqrt(n))
int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}


//calculates for 1 to n in (nlognlogn)
vector<int> phi;
void phiRange(int n) {
	phi.resize(n + 1);
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = i;

	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}

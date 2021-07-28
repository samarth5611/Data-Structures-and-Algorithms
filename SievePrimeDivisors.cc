

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


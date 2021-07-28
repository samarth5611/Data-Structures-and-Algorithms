
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



for (int i = 0 ; i < sz ; i++) {
	for (int j = 0 ; j < sz ; j++) {
		for (int k = 0 ; k < sz ; k++) {
			res.a[i][j] += ((a[i][k] % mod) * (p.a[k][j] % mod)) % mod;
		}
	}
}
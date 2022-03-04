//https://codeforces.com/problemset/problem/678/D
//https://codeforces.com/problemset/submission/678/115748318


struct matrix {
	vector<vector<int>> a;
	int sz;
	matrix (int n) {
		sz = n;
		a.resize(n);
		for (int i = 0 ; i < n ; i++)
			a[i].resize(sz);
	}
	void set(int x) {
		for (int i = 0 ; i < sz ; i++)
			for (int j = 0 ; j < sz ; j++)
				a[i][j] = x;
	}
	void print() {
		for (int i = 0 ; i < sz ; i++) {
			for (int j = 0 ; j < sz; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	}
	void iden() {
		set(0);
		for (int i = 0 ; i < sz ; i++)a[i][i] = 1;
	}

	matrix operator * (const matrix & p) {
		matrix res(p.sz);
		for (int i = 0 ; i < sz ; i++) {
			for (int j = 0 ; j < sz ; j++) {
				for (int k = 0 ; k < sz ; k++) {
					res.a[i][j] += ((a[i][k] % mod) * (p.a[k][j] % mod)) % mod;
				}
			}
		}
		return res;
	}
};

// M = Matrixexpo(M , n);
matrix Matrixexpo( matrix a , int y)
{
	matrix res(a.sz);
	res.iden();
	while (y) {
		if (y & 1)
			res = res * a;
		a = a * a;
		y = y / 2;
	}
	return res;
}



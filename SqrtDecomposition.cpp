struct sqrt_dec {
	int n;
	int b_s;
	vector<int> a;
	vector<int> b;
	sqrt_dec(int N) {
		n = N;
		b_s = sqrt(n) + 1;
		a.resize(n, 0);
		b.resize(sqrt(n) + 1, 0);
	}
	void precompute() {
		for (int i = 0; i < n; i++) {
			b[i / b_s] += a[i];
		}
	}
	int upd(int i, int val) {
		b[i / b_s] += val - a[i];
		a[i] = val;
	}
	int query(int l, int r) {
		int ans = 0;
		int b_l = l / b_s, b_r = r / b_s;
		if (b_l == b_r) {
			for (int i = l; i <= r; i++)
				ans += a[i];
		} else {
			int j = (b_l + 1) * b_s - 1;
			for (int i = l; i <= j; i++)
				ans += a[i];
			for (int i = b_l + 1; i < b_r; i++)
				ans += b[i];
			for (int i = b_r * b_s; i <= r; i++)
				ans += a[i];
		}
		return ans;
	}
};

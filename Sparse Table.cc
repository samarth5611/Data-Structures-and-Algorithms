struct sparse
{
	const int logn = 22;
	vector<vector<int>> dp;
	vector<int> floorlog;
	int n;

	sparse(int nn , vector<int> a) {
		n = nn;
		dp.resize(logn);
		floorlog.resize(n + 2 , 0);
		for (auto &it : dp )
			it.resize(n + 1 , 0);

		// Floor log2 calculations
		for (int i = 0 ; (1 << i) <= n ; i++) {
			for (int j = (1 << i) ;  j <= n and j < (1 << (i + 1)) ; j++)
				floorlog[j] = i;
		}

		// Precomputation
		for (int i = 0 ; i < n ; i++)
			dp[0][i] = a[i];

		for (int i = 1 ; (1 << i) <= n ; i++) {
			for (int j = 0 ; j + (1 << i) - 1 < n ; j++) {
				dp[i][j] = min(dp[i - 1][j] , dp[i - 1][j + (1 << (i - 1))]); // min,max,gcd,AND,OR
			}
		}
	}

	int qry(int l , int r) {  // query based on 0 indexing
		int len = r - l + 1;
		int k = floorlog[len];
		return min(dp[k][l] , dp[k][r - (1 << k) + 1]);;
	}

};


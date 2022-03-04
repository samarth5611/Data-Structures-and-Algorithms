
// The graph may have negative weight edges, but no negative weight cycles.


void floyd_warshall() {
	rep(k , 0 , N) {
		rep(i , 0 , N) {
			rep(j , 0 , N) {
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
			}
		}
	}
}

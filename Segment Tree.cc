struct node {
	node() {
	}
};

struct segtree
{
	vector<node> seg;
	vector<int> a;
	int n;
	void init(int nn , vector<int>&arr) {
		n = nn; seg.resize(4 * n + 5 ); a = arr;
	}

	void merge(node &a , node&b , node&c) {

	}

	int build(int ind , int L , int R) {
		if (L == R) {
			return 0;
		}
		int M = L + (R - L) / 2;
		build(2 * ind + 1 , L , M);
		build(2 * ind + 2 , M + 1 , R);
		merge(seg[ind] , seg[2 * ind + 1] , seg[2 * ind + 2]);
		return 0;
	}

	node qry(int ind , int L , int R , int l , int r) {

		if (l <= L  and R <=  r) return seg[ind];

		if (R < l  or L > r) return node();

		int M = L + (R - L) / 2;
		node left = qry(2 * ind + 1 , L , M , l , r);
		node right = qry(2 * ind + 2 , M + 1 , R , l , r);

		node ans;
		merge(ans , left , right);
		return ans;
	}

	int pUpdate(int ind , int L , int R , int idx , int x) {

		if (L == R) {
			seg[ind].ele += x;
			return 0;
		}
		int M = L + (R - L) / 2;
		if ( idx <= M)
			pUpdate(2 * ind + 1 , L , M , idx , x);
		else
			pUpdate(2 * ind + 2 , M + 1 , R , idx , x);

		merge(seg[ind] , seg[2 * ind + 1] , seg[2 * ind + 2]);
		return 0;
	}

	node qry(int l , int r) {
		return qry(0 , 0 , n - 1 , l , r);
	}
	void pUpdate(int idx , int x) {
		pUpdate(0 , 0 , n - 1 , idx , x );
	}

};
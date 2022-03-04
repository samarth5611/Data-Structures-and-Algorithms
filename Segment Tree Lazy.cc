struct node {
	int x;
	node() {
		x = 0;
	}
};

struct segtree {
	int n;
	vector<node> seg;
	vector<int> lazy;
	vector<bool> clazy;
	vector<int> a;

	void init(int nn) {
		n = nn;
		a.assign(n , 0);
		seg.resize(4 * nn + 5);
		lazy.resize(4 * nn + 5 , 0);
		clazy.assign(4 * nn + 5 , false);
	}
	void merge(node &a , node&b , node&c) {
		a.x = b.x + c.x;
	}
	void build(int ind , int l , int r) {
		if (l == r) {
			seg[ind].x = 0;
			lazy[ind] = 0;
			return ;
		}
		int mid = (l + r) / 2;
		build(2 * ind + 1 , l , mid);
		build(2 * ind + 2 , mid + 1 , r);
		merge(seg[ind] , seg[2 * ind + 1] , seg[2 * ind + 2]);
		return ;
	}
	void pushdown(int ind , int l , int r) {

		if (l != r) {
			clazy[2 * ind + 1] = 1;
			lazy[2 * ind + 1] += lazy[ind];

			clazy[2 * ind + 2] = 1;
			lazy[2 * ind + 2] += lazy[ind];
		}
//	  |>  write logic for pushdown and merging in current node
		seg[ind].x += (r - l + 1) * lazy[ind];
		lazy[ind] = 0;
		clazy[ind] = 0;
	}

	node qry(int ind , int l , int r , int ql , int qr) {
		if (clazy[ind])
			pushdown(ind , l , r);

		if (ql > r  or qr < l)
			return node();

		if (ql <= l  and r <= qr)
			return seg[ind];

		int mid = (l + r) / 2;
		node left = qry(2 * ind + 1 , l , mid , ql , qr);
		node right = qry(2 * ind + 2 , mid + 1 , r , ql , qr);
		node ans; merge(ans , left , right);
		return ans;
	}

	void rangeupd(int ind , int l , int r , int ql , int qr , int x) {
		if (clazy[ind])
			pushdown(ind , l , r);

		if (ql > r  or qr < l  or l > r)
			return ;

		if (ql <= l  and r <= qr) {
			clazy[ind] = 1;
			lazy[ind] += x;
			pushdown(ind , l , r );
			return ;
		}
		int mid = (l + r) / 2;
		rangeupd(2 * ind + 1 , l , mid, ql , qr , x);
		rangeupd(2 * ind + 2 , mid + 1 , r, ql , qr , x);
		merge(seg[ind] , seg[2 * ind + 1] , seg[2 * ind + 2]);
	}
};
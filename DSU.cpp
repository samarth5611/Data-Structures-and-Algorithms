struct DSU {
	int n , components;
	vector<int> par , sz;

	DSU(int nn) {
		n = components = nn;
		par.assign(n + 5 , 0);
		sz.assign(n + 5 , 1);
		iota(all(par) , 0);
	}
	int root(int x) {
		if (x == par[x])return x;
		return par[x] = root(par[x]);
	}
	void merge(int x , int y) {
		x = root(x);
		y = root(y);
		if (x == y)return;
		if (sz[x] < sz[y])swap(x , y);
		par[y] = x;
		sz[x] += sz[y];
		sz[y] = 0;
		components--;
	}
};
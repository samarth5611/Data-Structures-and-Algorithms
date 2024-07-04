struct DSU{
	int n, components;
	vector<int> sz, par;
	
	DSU(int N){
		n = components = N;
		sz = vector<int>(n+1, 0);
		par = vector<int>(n+1, 0);
		iota(par.begin(), par.end(), 0);
	}
	
	int root(int node){
		if(node == par[node])return node;
		return par[node] = root(par[node]);
	}
	
	void merge(int node1, int node2){
		node1 = root(node1);
		node2 = root(node2);
		if(node1 == node2)return;
		if(sz[node1] < sz[node2])swap(node1, node2);
		par[node2] = node1;
		sz[node1] += sz[node2];
		sz[node2] = 0;
		components--;
	}
};

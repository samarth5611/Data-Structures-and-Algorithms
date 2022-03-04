// for lexiograhically minimum order use priority queue

vector<int> order; 
// function for checking if TopoLogical Sort Exists
bool Toposort(int n)  
{	

	queue<int> q;
	vector<int> in(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:g[i])
			in[it]++;

	for(int i = 1; i <= n; i++)
	{
		if(!in[i])
			q.push(i);
	}

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		for(auto &v:g[u])
		{
			in[v]--;
			if(!in[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}

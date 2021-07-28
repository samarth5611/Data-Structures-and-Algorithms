
vector<int> p;
// set<int> p;
int primes(const int N = 1e6)
{
	p.push_back(2);
	// p.insert(2);
	vector<bool> vis(N , 0);
	for (int i = 2 ; i < N ; i += 2) vis[i] = 1;
	for (int i = 3 ; i * i < N ; i += 2) {
		if (vis[i] == 0) {
			for (int j = i * i ; j < N ; j += i )
				vis[j] = 1;
		}
	}
	for (int i = 3 ; i < N ; i++)
		if (vis[i] == 0) {
			p.push_back(i);
			//p.insert(i);
		}
	return 0;
}


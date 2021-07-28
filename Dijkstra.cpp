#include "bits/stdc++.h"
using namespace std;

#define int long long
#define inf 1e18
#define ss second
#define ff first

const int N = 1e5 + 5;

int n , m;
vector<pair<int , int>> gr[N];
vector<int> dis , pre;

int Dijkstra(int src , int dest) {
	pre = dis = vector<int>(n + 1 , inf);
	fill(pre.begin(), pre.end() , -1);

	set<pair<int , int>> s;
	s.insert({0 , src});
	dis[src] = 0;

	while (!s.empty()) {
		auto x = *(s.begin());
		s.erase(s.begin());

		for (auto &i : gr[x.ss]) {

			if (dis[i.ff] > x.ff + i.ss) {
				s.erase({dis[i.ff] , i.ff});
				dis[i.ff] = i.ss + dis[x.ss];
				pre[i.ff] = x.ss;
				s.insert({dis[i.ff] , i.ff});
			}
		}
	}

	if (dis[dest] >= 1e17) {
		cout << -1 << endl;
		return 0;
	}

	vector<int> ans;
	while (dest  != src) {
		ans.push_back(dest);
		dest = pre[dest];
	}
	ans.push_back(src);
	reverse(ans.begin(), ans.end());
	for (auto &i : ans)
		cout << i << " ";
	return 0;
}



int32_t main() {
	cin >> n >> m;
	for (int i = 0 ; i < m ; i++) {
		int x , y , w;
		cin >> x >> y >> w;
		gr[x].push_back({y , w});
		swap(x , y);
		gr[x].push_back({y , w});
	}

	Dijkstra(1 , n);

	return 0 ;
}

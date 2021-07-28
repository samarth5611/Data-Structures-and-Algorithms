/// Spoj : DQUERY - D-query

#include "bits/stdc++.h"
using namespace std;

int B = 174; //bucket size
const int N = 1e6 + 5;
int fr[N];

struct qry {
	int l , r , id;
};
struct comp {
	bool operator()( const qry&a , const qry& b) {
		if (a.l / B != b.l / B)
			return a.l < b.l;
		return a.r < b.r;
	}
};
int n;
vector<int> a;
int res = 0;

void add(int x) {
	if (fr[x] == 0)
		res++;
	fr[x]++;
}

void rem(int x) {
	if (fr[x] == 1)
		res--;
	fr[x]--;

}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	mem(fr , 0);
	cin >> n;
	a.resize(n);

	for (int i = 0; i < n ; i++)
		cin >> a[i];

	vector<qry> q;
	int m;
	cin >> m;
	for (int i = 0 ; i < m ; i++) {
		qry t;
		t.id = i;
		cin >> t.l >> t.r;
		q.push_back(t);
	}

	sort(q.begin(), q.end() , comp());

	// for (auto x : q)
	// 	cout << x.l << " " << x.r << " " << x.id << endl;

	vector<int> ans(n);


	int curl = 0;
	int curr = 0;
	add(a[0]);

	for (int i = 0 ; i < m ; i++) {
		int l = q[i].l - 1 ;
		int r = q[i].r - 1;
		int idx = q[i].id;

		// cout << l << " " << r << " " << idx << endl;

		while (curr < r) {
			curr++;
			add(a[curr]);
		}

		while (curr > r) {
			rem(a[curr]);
			curr--;
		}

		while (curl < l) {
			rem(a[curl]);
			curl++;
		}

		while (curl > l) {
			curl--;
			add(a[curl]);
		}

		// for (int i = 0 ; i < 5 ; i++) {
		// 	cout << fr[i + 1] << " ";
		// }
		// cout << endl;
		ans[idx] = res;

	}

	for (int i = 0 ; i < m ; i++)
		cout << ans[i] << endl;


	return 0 ;
}

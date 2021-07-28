#include "bits/stdc++.h"
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif


	int a , b;
	cin >> a >> b;
	int c = 5;

	auto sum = [&]()
	{
		return a + b + c;
	};

	cout << sum() << endl;

	return 0 ;
}

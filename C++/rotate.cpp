#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(), x.end()
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif


// in such a way that the element pointed by middle becomes the new first element
// LEFT ROTATION :
// The 3th index of vector becomes first element. vec.begin() + 3 will rotate vector 3 times left
// RIGHT ROTATION :
// The 3th last index of vector becomes first element. vec.begin()+vec.size()-3 will rotate vector 3 times right

	string s; cin >> s;

	rotate(s.begin(), s.begin() + s.size() - 3 , s.end());
	cout << s << endl;
	rotate(s.begin(), s.begin() + 2 , s.end());
	cout << s << endl;
	return 0 ;
}

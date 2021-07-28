#include "bits/stdc++.h"
using namespace std;

struct pt3d {
	int x , y , z;
};

pt3d cross(pt3d &a , pt3d &b )
{
	pt3d res;
	res.x = a.y * b.z - a.z * b.y;
	res.y = -(a.x * b.z - a.z * b.x);
	res.z = (a.x * b.y - a.y * b.x);

	return res;
}

int dot(pt3d &a , pt3d &b) {
	int res = a.x * b.x + a.y * b.y + a.z * b.x;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif

	pt3d a , b;
	cin >> a.x >> a.y >> a.z;
	cin >> b.x >> b.y >> b.z;


	pt3d res = cross(a , b);


	cout << res.x << " " << res.y << " " << res.z << endl;


	return 0 ;
}

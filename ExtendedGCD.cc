#include "bits/stdc++.h"
using namespace std;


// find the solutions(x , y) of ax + by = gcd(a , b)
int gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}
// find ONLY solution of ax + by  = c
pair<int, int> solve_eq(int a , int b , int c) {
	int g = __gcd(a , b);
	if (c % g)              // No Solution
		return {0, 0};
	int x = 0 , y = 0;
	gcd(a , b , x , y);
	return {x*c / g , y*c / g};
}

//find ALL solution of ax + by = c
//x_new = x - k(b/g)
//y_new = y + k(a/g)     k can be ..-2,-1,0,1,2....

int a , b , x , y;

int main() {
	freopen("in.txt", "r", stdin);

	int a , b , c , x , y;
	cin >> a >> b >> c;

	auto p = solve_eq(a , b , c);
	cout << p.first << " " << p.second << endl;



	return 0 ;
}

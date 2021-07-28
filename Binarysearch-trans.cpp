#include "bits/stdc++.h"
using namespace std;

int FIRSTTRUE(function<bool(int)> f, int lb, int rb) {
	while (lb < rb) {
		int mb = (lb + rb) / 2;
		f(mb) ? rb = mb : lb = mb + 1;
	}
	return lb;
}
int LASTTRUE(function<bool(int)> f, int lb, int rb) {
	while (lb < rb) {
		int mb = (lb + rb + 1) / 2;
		f(mb) ? lb = mb : rb = mb - 1;
	}
	return lb;
}
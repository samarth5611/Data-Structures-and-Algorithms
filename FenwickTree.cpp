// update the element
// get the prefix sum

struct fenwick {

	int n;
	vector<int> bit;

	fenwick(int nn) {
		n = nn;
		bit.assign(n + 1 , 0);
	}

	void upd(int idx , int x) {

		while (idx <= n) {
			bit[idx] += x;
			idx += (idx & (-idx));
		}
	}

	int sum(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans += bit[idx];
			idx -= (idx & -idx);
		}
		return ans;
	}

	int rsum(int l , int r) {
		return sum(r) - sum(l - 1);
	}

	// binary lifting on fenwick tree
	//returns first index such that sum[idx] >= x
	int search(int x) {

		int cursum = 0 , idx = 0;
		for (int i = log2(n) + 2  ; i >= 0 ; i--) {
			if (idx + (1 << i) < n + 1  and  cursum + bit[idx + (1 << i)] < x) {
				idx += (1 << i);
				cursum += bit[idx];
			}
		}
		return idx + 1;
	}


};


// ( x & -x)  right most bit set

// remove  right most bit from a number x - (x & -x)
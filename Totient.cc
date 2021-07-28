// phi-function ϕ(n),counts the no of integer between 1 and n inclusive,
// which are coprime to n

// for prime number(p), ϕ(p) = p-1

// Calculates for integer in (sqrt(n))
int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}


//calculates for 1 to n in (nlognlogn)
vector<int> phi;
void phiRange(int n) {
	phi.resize(n + 1);
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = i;

	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}
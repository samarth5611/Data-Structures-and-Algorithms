int power(int a , int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = a * a;
        a %= mod;
        b /= 2;
    }
    return ans % mod;
}
 
int fact[N] , ifact[N];
 
void pre() {
    fact[0] = 1;
    ifact[0] = 1;
    for (int i = 1 ; i < N ; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        ifact[i] = power(fact[i] , mod - 2);
    }
}
 
int ncr(int n , int r) {
    int ans = 0;
    ans = fact[n];
    ans = ans * (ifact[r]);
    ans = ans % mod;
    ans = ans * (ifact[n - r]);
    ans %= mod;
    return ans;
}
#include "bits/stdc++.h"
using namespace std;

#define pii pair<int , int>
#define ff first
#define ss second

struct cmp
{
    bool operator()( pii a ,  pii b)const
    {
        if (a.ff < b.ff)
            return true;
        else if (a.ff == b.ff and a.ss > b.ss)
            return true;
        return false;
    }

};

int solve()
{
    set< pair<int , int> , cmp> s;


    return 0;
}
int32_t main() {

    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(20);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    solve();
    return 0 ;
}

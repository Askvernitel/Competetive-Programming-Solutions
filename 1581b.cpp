#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){ 
        int n, m, k;

        cin >> n >> m >> k;

        int t = min(n,(int)3); 

        int d = ((n-1)*n)/2;
        if(d == m){
                t = min(t, (int)2);
        }

        if(t < k && d >= m && n-1 <= m){
                cout << "YES\n";
        }else{
                cout << "NO\n";
        }
}

signed main(){ 
        int tc;
        cin >> tc;


        while(tc--) solve();
}

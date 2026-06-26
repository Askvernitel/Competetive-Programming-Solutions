#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
        int n;
        cin >> n;


        if(n == 10){ 
                cout << -1 << '\n';
                return;
        }

        
        int d = n%12;
        if(d == 10){ 
                d+=12;
        }
        cout << d << " " << n-d << '\n';
}
signed main(){
        int tc; 
        

        cin >> tc;

        while(tc--) solve();
}

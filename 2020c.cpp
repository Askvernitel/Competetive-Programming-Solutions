#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    
    int b, c, d;

    cin >> b >> c >> d;

    int bits[62];
    if(b - d > 0){cout << -1 << '\n'; return;}
    memset(bits, 1,sizeof(bits));
    int t = 0;
    while(c != 0){
        if(c & 1) bits[t] = 0;
        c = c >> 1;
        t++;
    }
    int k = d-b, pos = 1;
    int j = 0; 
    int ans = 0;
    while(j < 62){
        if((k >> j) & 1){
            if(!bits[j]){
                if((b >> j)){
                    k = (k^(b>>j));
                    j++;
                    continue;
                }
                pos = 0;
                break;
            }
            //ans+= (1 << j);
        }
        j++;
    }

    if(!pos){cout << -1 << '\n'; return;}
    if((k|b) - (k&c) != d){cout << -1 <<'\n'; return;}
    cout << k << '\n';
    



}

signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

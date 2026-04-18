#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int w, b;
    cin >> w >> b;


    int p = w + b;
    int l = 1, r=2000000000;
    

    while(l < r){ 
        int m = l + (r-l+1)/2;
        
        if((m*(m+1))/2 > p){
            r = m-1;
        }else{
            l = m;
        }

    }

}
signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

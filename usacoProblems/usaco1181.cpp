#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    //2z - y  z >= y/2
    int prev = -1;
    int pos = 1;
    int ans = 0;
    for(int i = 0;i<n-1;i++){
        if(a[i+1] > a[i]){ 
            
            if(i+2 >= n){ 
                pos = 0; break;
            }
            
            int d = a[i+1] - a[i];
            a[i+1]-=d;
            a[i+2]-=d;
            if(a[i+2]< 0) {
                pos = 0; break;
            }
            
            ans += (d)*2;
        }else if(a[i+1] < a[i]){ 
            if((i+1)%2){ 
                pos = 0;
                break;
            }
            int d = a[i]-a[i+1];
            ans += d*(i+1);

        }
    }
    if(!pos) ans = -1; 
    cout << ans << '\n';

}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

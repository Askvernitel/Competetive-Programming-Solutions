#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
signed main(){
    int n;
    cin >> n;
    
    if(n==2){
        cout << 2;
        return 0;
    }
    int ans = 1;
    for(int i =0;i<n;i++){
        ans=(ans*2)%mod;
    }
    
    cout << ans%mod;

}

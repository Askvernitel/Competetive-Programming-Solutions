#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int inf = 1e16+7;
    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    int f[s+3];
    for(int i =0;i<s+3;i++){
        f[i] = inf;  
    }
    f[0] = 0 ;
   
    for(int i =0;i<s;i++){
        for(int j=0;j<n;j++){
            if(f[i] != inf){
                if(i + a[j] <= s){
                    f[i+a[j]] = min(f[i+a[j]], f[i] + 1); 
                }
            }
        }
    }
    int ans = f[s];
    if(f[s] == inf) ans = -1;
    cout << ans;
    
}

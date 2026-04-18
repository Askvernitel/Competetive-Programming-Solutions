#include <bits/stdc++.h>

#define int long long
using namespace std;

int const mod = 7;
signed main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;

    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int prefd[n+1];
    int pref[n+1];
    pref[0] = 0;
    prefd[0] = 0;
    for(int i =1;i<=n;i++){
        pref[i] = pref[i-1]+a[i];
        prefd[i] = pref[i]%mod;
    }

    int m[7];
    int ans = 0;
    memset(m, -1, sizeof(m));
    for(int i =0;i<=n;i++){
        if(m[prefd[i]] != -1){
            ans = max(ans,i - m[prefd[i]]);
//            cout << i << '\n';
        }else
        m[prefd[i]] = i;
    }

    cout << ans;
    
    

}

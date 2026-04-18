#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0;i<n;i++){cin >> a[i]; sum+=a[i];}
    int ans = 0, s = 0;
    for(int i =1;i<n;i++){
        if(s+a[i] < 0){s=0; continue;} 
        s+=a[i];
        ans = max(s,ans);
    }
    s=0;
    for(int i=0;i<n-1;i++){
        if(s+a[i] < 0){s=0; continue;}
        s+=a[i];
        ans = max(s,ans);
    }
    //cout << ans;
    //cout << sum;
    if(ans < sum) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}

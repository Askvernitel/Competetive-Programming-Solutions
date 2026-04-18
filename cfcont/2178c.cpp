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
    int ans = 0;
    if(a[0] < 0){ 
        int p1 = 0, p2 = a[0];

        for(int i =1;i<n;i++){
            p1-=a[i];
        }
        int c = 0;
        for(int i =n-1;i>=0;i--){
            if(a[i] >= 0){
                c=i;
                break;
            }
        }
        int u = a[c];
        for(int i =c;i<n;i++){
            u = min(u, abs(a[i]));
        }
        for(int i =1;i<n;i++){
            p2 += abs(a[i]);
        }
        ans= max(p2 - u, p1);


    }else{
        int c = 0;
        for(int i =n-1;i>=0;i--){
            if(a[i] >= 0){
                c=i;
                break;
            }
        }
        int u = a[c];
        for(int i =c;i<n;i++){
            u = min(u, abs(a[i]));
        }
        int t = 0;
        for(int i =0;i<n;i++){
            t += abs(a[i]);
        }
        ans= t - u;

    }
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

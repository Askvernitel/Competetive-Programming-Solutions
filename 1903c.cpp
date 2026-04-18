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

    int suf[n+2];
    suf[n]=0;
    suf[n+1] = 0;
    for(int i = n-1;i>=0;i--){
        suf[i] = suf[i+1] +a[i];
    }
    int ans = 0;
    int cof = 1;
    int j =0;
    while(j<n){
        int sum = 0;
        sum+=a[j];
        while(j<n+2 && suf[j+2]+a[j+1] < 0){
            j++;
            sum+=a[j];
        }
        sum*=cof;
        j++;
        ans+=sum;
        cof++;
    }
    cout << ans << '\n';

}
signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int ans=0;
    int idx =n;
    int esum = 0;
    for(int i=0;i<n;i++){
        if(!(i%2) && a[i] > 0){ 
            idx = i;
            break;
        }
        if(i%2 && a[i] > 0) esum+=a[i];
    }
    for(int i=n-1;i>=idx;i--){
        if(a[i] > 0) ans+=a[i];
    }
    int max_sum =0;
    for(int i =0;i<idx;i++){
        if(!(i%2)) max_sum = max(a[i]+esum, max_sum);
        else{
            if(a[i] > 0) esum-=a[i];
            max_sum = max(esum,max_sum);
        }
    }
    cout << ans+max_sum << '\n';
}
signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}

#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    int pref[n+1];
    pref[0] = 0;
    for(int i =1;i<=n;i++){
        pref[i] = pref[i-1] + a[i-1];
    }
    int ans=n-1;
    for(int i=1;i<=n;i++){
        int t = i;
        int sum = pref[i];
        int pos = 1;
        int cans = 0;
        cans+=i-1;
//        cout << sum << '\n';
        for(int j = t;j<n;j++){
            int cpos = 0; 
            for(int k = 1;k<=n-j;k++){
                int csum =pref[j+k]-pref[j];
  //              cout << "K:" << pref[j+k] << " ";
                if(csum == sum){j=j+k-1; cans+=k-1; cpos=1; break;}
                if(csum > sum){
                    pos = 0;
                    break;
                }
            }
    //        cout << '\n';
            if(!cpos) pos = 0;
            
            if(!pos) break;
        }
        if(pos) ans = min(cans, ans);
    }
    cout << ans << '\n';
}


int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}

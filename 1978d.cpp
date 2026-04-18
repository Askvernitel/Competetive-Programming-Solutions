#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n, c;
    cin >> n >> c;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    int pref[n+1], suf[n+1], s[n+1];
    pref[0] = 0; suf[n] = 0, s[0]=0;
    for(int i = 1;i<=n;i++){
        pref[i] = max(pref[i-1], a[i-1]);
        s[i] = s[i-1] + a[i-1];
    }
    for(int i = n-1;i>=0;i--){
        suf[i] = max(suf[i+1], a[i]);
    }

    for(int i = 0;i<n;i++){
        int cnt = 0;
        if((pref[i] >= a[i] && i !=0) || (a[0] + c >= a[i] && i != 0)){
            cnt += i;
            if(suf[i] > a[i] + c + s[i]) cnt++;
        }else if((suf[i] > a[i] && i != 0)){
            cnt+=i;
            if(suf[i] > a[i] + c + s[i]) cnt++;

        }else if(a[i] + c < suf[i] && i == 0){
            cnt++;
        }

        cout << cnt <<  " ";
    }
    cout << '\n';
}
signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("hps.in", "r",stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        char ch;
        cin >> ch;
        if(ch == 'P'){
            a[i] = 0;
        }else if(ch == 'H'){
            a[i] = 1;
        }else{
            a[i] = 2;
        }
    }
    int pref[n+1][3], suf[n+1][3];
    for(int i =0;i<3;i++){pref[0][i] = 0; suf[n][i] = 0;}
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++) pref[i][j] = pref[i-1][j];
        pref[i][a[i-1]]++;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<3;j++) suf[i][j] = suf[i+1][j];
        suf[i][a[i]]++;
    }
    int ans = 0;
    for(int i =0;i<n;i++){
        int pr = max({pref[i][0], pref[i][1], pref[i][2]});
        int sf = max({suf[i][0], suf[i][1], suf[i][2]});
        ans = max(ans, pr + sf);
    }
    cout << ans << '\n';
}

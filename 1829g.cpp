#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
int arr[2024][2025];
void calc(){ 
    memset(arr, 0, sizeof(arr));
    int am = 1;
    int p = 1;
    for(int i = 0;i<2024;i++){
        for(int j = 0;j<am;j++){
            arr[i][j+1] = arr[i][j] + p*p;
            p++;
        }
        am++;
    }
}
void solve(){
    cin >> n;
    int am = 1;
    int c = 0;
    for(int i = 1;i<2024;i++){
        if(am+i > n){break;}
        c = i;
        am+=i;
    }
    int k = n-am;
    int p = am+c-n;
    int ans = 0;
    for(int i = c;i>=0;i--){
        ans += arr[i][i-p+1]-arr[i][k];
        k--;
        p--;
        p = max(p,(int)0);
        k = max(k,(int)0);
        
    }
    cout << ans << '\n';
}
signed main(){
    calc();
    int tc;
    cin >> tc;
    while(tc--) solve();
}

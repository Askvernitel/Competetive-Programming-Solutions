#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a[m];
    for(int i =0;i<n;i++){
        
        for(int j=0;j<m;j++){
            int p;
            cin >> p;
            a[j].push_back(p);
        }
    }
    if(n == 1){ 
        cout << 0 << '\n';
        return;
    }
    for(int i =0;i<m;i++) sort(a[i].begin(), a[i].end());


    int ans = 0;
    for(int i= 0;i<m;i++){

        for(int j=0;j<n-1;j++){
            ans += abs(a[i][j+1]-a[i][j])*((j*(n-j-1))+(n-j-1));
        
        }
    }
    cout << ans << '\n';

}

signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}   

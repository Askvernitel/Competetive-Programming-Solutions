#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;

    int a[n][m];
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    int arr[n];
    for(int i =0;i<n;i++){
        int sum =0;
        for(int j =0;j<m;j++){
            sum+=a[i][j];
        }
        
        arr[i] = sum;
    }
    sort(arr, arr+n, greater<int>());
    int c = 0;
    int ans =0;
    for(int i =0;i<n;i++){
        ans+=arr[i]*((n*m-(i+1)*m) +1);
    }
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j=0;j<m-1;j++){
            sum+=a[i][j];
            ans+=sum;
        }
    }
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

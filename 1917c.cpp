#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k, d;
    cin >> n >> k >> d;
    int a[n], b[k];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<k;i++){
        cin >> b[i];
    }
    int ans=0;
    for(int i=0;i<min(2*n,d);i++){
        int arr[n+1];
        memset(arr, 0, sizeof(arr));
        int t = i;
        for(int j = 0;j<i;j++){ 
            arr[b[j%k]] -= 1;
        }
        int cnt = 0;
        for(int j =0;j<n;j++){
            t+=arr[j];
            if(a[j] + t == j+1) cnt++;
        }
        cnt +=(d-i-1)/2;
        ans = max(cnt, ans);
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

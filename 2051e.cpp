#include <bits/stdc++.h>

using namespace std;
#define int long long

int a[200001], b[200001];
int n, k;
int bs(int x){
    int l =-1, r=n;
    
    while(r-l > 1){ 
        int m = (r+l)/2;

        if(b[m] < x){ 
            l = m;
        }else{
            r = m;
        }
    }
    return r;
}
int bs2(int x){ 
    int l = -1, r=n;

    while(r-l>1){
        int m = (r+l)/2;

        if(a[m] >= x){ 
            r = m;
        }else{
            l = m;
        }
    }
    return r;
}
int cnt = 0;
void solve(){
    cnt++;
    cin >> n >> k;
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+n);
    int ans = 0;
    for(int i =0;i<n;i++){
        int p = bs2(b[i]);
        if(p-i <= k){
            ans = max(b[i]*(n-i), ans);
        }
        while(i+1 < n && b[i] == b[i+1]) i++;
    }

    for(int i = n-1;i>=0;i--){
        int lo = bs(a[i]);
        if(i-lo > k) continue;
        ans = max(a[i]*(n-lo), ans);
    }
    cout << ans << '\n';
   
}
signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, x, y;
int a[200001];
int bs(int x,int l, int t){ 
    int r=n;
    function<bool(int)> f = [&](int m){ 
            return (t)?a[m] >= x:a[m]>x;
    };

    while(r-l >1){ 
        int m = (r+l)/2;

        if(f(m)){
            r = m;
        }else{
            l = m;
        }
    }

    return ((t)?(r):(l));
}
void solve(){

    cin >> n >> x >> y;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i =0;i<n;i++) sum+=a[i];

    int up = sum-x;
    int low = sum-y;
    sort(a, a+n);
    int ans =0;
    for(int i =0;i<n;i++){
        int lo=low-a[i];
        int hi=up-a[i];

        int p1 = bs(lo,i,1);
        int p2 = bs(hi,i,0);

        if(p2 - p1 >= 0){ 
            ans+=(p2-p1+1);
        }
    }
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

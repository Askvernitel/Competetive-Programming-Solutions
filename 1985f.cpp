#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
    int h, n;
    cin >> h >> n;
    int a[n], c[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i =0;i<n;i++){
        cin >> c[i];
    }
    function<bool(int)> good = [&](int m){ 
        int hp = 0;
        for(int i =0;i<n;i++){
            hp+=a[i];
            hp+=((m-1)/c[i])*a[i];
        }

        return hp >=h;
    };

    int r = 1;
    while(!good(r)) r*=2;
    int l = 1;

    while(r-l>1){ 
        int mid = (r+l)/2;
        if(good(mid)){ 
            r = mid;
        }else{ 
            l = mid;
        }
    }

    cout << r << '\n';

}
signed main(){
    int tc;

    cin >> tc;

    while(tc--){
        solve();
    }
}

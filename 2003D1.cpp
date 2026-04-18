#include <bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    int p = 0;
    for(int i =0;i<n;i++){
        int l;
        cin >> l;
        int a[l];
        int mex = 0;
        for(int j=0;j<l;j++) cin >> a[j];
        sort(a, a+l);
 
        for(int j =0;j<l;j++){
            if(a[j] == mex) mex++;
        }
        int next_mex = mex + 1;
        for(int j =0;j<l;j++){
            if(a[j] == next_mex) next_mex++;
        }
        p=max(next_mex,p);
    }
//    cout << p << '\n';
    int ans = 0;
//    cout << "HEY" << '\n';
    if(m > p){ans+=p*(p+1);}
    if(m > p){ans+=((((p+1) + m))*(m-p))/2;}
    if(m <= p){ans+=p*(m+1);}

    cout << ans << '\n';
}


signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}   

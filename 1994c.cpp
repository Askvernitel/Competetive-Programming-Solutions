#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, x;
int k=0;
void add(int t){
    if(k + t > x){ 
        k = 0; return;
    }
    k+=t;
}
void remove(int t){
    k-=t;
}
bool good(){ 
    return k == 0;
}
void solve(){
    cin >> n >> x;
    k=0;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int ans =0;
    int l = 0;
    for(int r =0;r<n;r++){
        add(a[r]);
        while(!good()){ 
            remove(a[l++]);
        }
        ans+=(r-l+1);
    }
    cout << ans << '\n';
}
signed main(){
    int tc;
    cin >>tc;
    while(tc--) solve();
}

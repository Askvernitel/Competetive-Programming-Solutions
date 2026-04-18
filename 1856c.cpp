#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[1001];

int n, k;
bool f(int m, int idx){ 
    int idxm = -1;
    for(int i =idx;i <n;i++){
        if(m <= a[i]-idx+i){idxm=i; break;}
    }
    if(idxm == -1) return false;
    int v = 0;
    for(int i=idxm-1;i>=idx;i--){
        v+=(m+idx-i-a[i]);
    }
    return v <= k;
    
}
void solve(){
    cin >> n >> k;
    int maxv = 0;
    for(int i =0;i<n;i++){cin >> a[i]; maxv = max(maxv,a[i]);}

    int ans = maxv;
    for(int i =0;i<n;i++){
        int l=maxv, r=maxv+n;
        while(r-l>1){ 
            int m = (l+r)/2;
            if(f(m, i)){ 
                l = m;
            }else{ 
                r = m;
            }
        }
        ans = max(l, ans);
    }
    cout << ans << '\n';



}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

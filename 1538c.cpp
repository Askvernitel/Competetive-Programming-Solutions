#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[200001];
int n,l,r;
int bs(int x, int op){ 
    int l =-1,r = n;
    auto comp = [&](int v){ 
            if(op) return v >= x;
            else return v > x;
    };
    while(r-l>1){ 
        int m = (l+r)/2;
        if(comp(a[m])){ 
            r =m;
        }else{
            l=m;
        }
    }

    return (op)?r:l;
}


void solve(){
    cin >> n >> l >> r;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int ans =0;
    for(int i =0;i<n;i++){
        int k = bs(l-a[i], 1), v = bs(r-a[i], 0);
        if(v-k< 0) continue;
        ans+=(v-k+1);
        if(l-a[i] <= a[i] && r-a[i] >= a[i]) ans--;
    
    }
    cout << (ans+1)/2 << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

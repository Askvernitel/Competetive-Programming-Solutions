#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;

    cin >> n;
    int a[n], b[n];

    
    for(int i =0;i<n;i++) cin >> a[i];

    for(int i =0;i<n;i++) cin >> b[i];
    int cnta = 0, cntb = 0 ;
    for(int i =0;i<n;i++){
        if(a[i] > b[i]) cnta+=a[i];
        if(a[i] < b[i]) cntb+=b[i];
        if(a[i] != b[i]){a[i] = 0; b[i]=0;}
    }

    for(int i =0;i<n;i++){
        if(cnta >= cntb && a[i] == -1) cnta += a[i];
        else if(cnta < cntb && a[i] == -1) cntb += a[i];

        if(cnta < cntb && a[i] == 1) cnta += a[i];
        else if(cnta >=cntb && a[i] == 1) cntb += a[i];
    }
    cout << min(cnta, cntb) << '\n';

    
}


int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

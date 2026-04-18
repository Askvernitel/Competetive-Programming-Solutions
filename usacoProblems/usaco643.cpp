#include <bits/stdc++.h>
#define int long long 
using namespace std;




signed main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n,k;

    cin >> n>> k;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    sort(a, a+n);
    int mx1 = 0, mx2 = 0;
    int l = 0;
    for(int r =0;r<n;r++){

        while(a[r] - a[l] > k){
            l++;
        }
        if(mx1 > mx2){ 
            mx2 = max(mx2, r-l+1);
        }else{
            mx1 = max(mx1, r-l+1);
        }
    }
    cout << mx1 + mx2 << '\n';
}

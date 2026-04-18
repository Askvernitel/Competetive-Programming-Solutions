#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int n,q;
    cin >> n >> q;

    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    
    int pref[n];
    pref[0] = a[0];
    for(int i =0;i<n-1;i++){
        pref[i+1] = pref[i] +a[i+1];
    }

    while(q--){ 
        int l, r;
        cin >> l >> r;
        r--; l--;
        int sum = 0;
        sum += pref[r];
        if(l >=0) sum-=pref[l];
        cout << sum << '\n';
    }
}

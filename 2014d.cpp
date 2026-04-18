#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, d, k;
    cin >> n >> d >> k;
    int a[n+1], pref[n+1];
    memset(a,0,sizeof(a));
    memset(pref,0,sizeof(pref));
    while(k--){ 
        int l, r;
        cin >> l >> r;

        l--; r--;
        a[l]++;
        a[r+1]--;
        pref[l]++;
    }
    for(int i=1;i<n;i++) a[i] += a[i-1];
    for(int i=1;i<n;i++) pref[i] = pref[i-1] + pref[i];
    
/*    for(int i =0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i =0;i<n;i++){
        cout << pref[i] << " ";
    }
    cout << endl;*/
    int maxv = 0, k1 = 0, minv = INT_MAX, k2 = 0;
    for(int i=0;i<n-d+1;i++){
        if(maxv < a[i] + pref[i+d-1] - pref[i]){
            maxv = a[i] + pref[i+d-1] -pref[i];
            k1 = i+1;
        }
        if(minv > a[i] + pref[i+d-1] - pref[i]){
            minv = a[i] + pref[i+d-1] - pref[i];
            k2 = i+1;
        }
    }

    cout << k1 << " " << k2 << '\n';
    

}

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}

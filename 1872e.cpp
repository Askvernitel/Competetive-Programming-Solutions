#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    string s;
    cin >> s;
    int pref[n+1];
    memset(pref, 0, sizeof(pref));
    int one = 0, zero =0;
    for(int i = 1;i<n+1;i++){
        pref[i] = pref[i-1] ^ a[i-1];
        if(s[i-1] == '1'){
            one = one ^ a[i-1];
        }else{
            zero = zero ^ a[i-1];
        }
    }
    
    int q;
    cin >> q;
    while(q--){ 
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin>> l >> r; 
            l--;r--;
            int k =pref[r+1] ^ pref[l];
            zero = zero ^k;
            one = one ^ k;
        }else{
            int g; 
            cin >> g;
            if(g){
                cout << one << " ";
            }else{
                cout << zero << " ";
            }
        }

    }
    cout << '\n';
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

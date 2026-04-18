#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int a[n];
    
    for(int i =0;i<n;i++) cin >> a[i];
    if(n == 1){cout << a[0] << '\n'; return;}
    int mx = a[1], k = 1;
    for(int i =1;i<n;i++){
        if(mx < a[i]){
            mx = a[i];
            k = i;
        }
    }
    int maxv = a[k-1], t = k;
    int p = 0;
    if(k == n-1 && a[0] > a[k-1]){
        p = 1;
        t = k;
    }
    for(int i = k -1;i >=0;i--){
        if((a[0] >= a[i] && i != k-1) || p){
            break;
        }else{t--;}
    }
    for(int i =k;i<n;i++){
        cout << a[i] << " ";
    }
    for(int i =k-1; i>=t;i--){
        cout << a[i] << " ";
    }
   
    for(int i =0;i<t;i++){
        cout << a[i] << " ";
    }

    cout << '\n';


}


int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

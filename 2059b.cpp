#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
        
    int cur = 1;
    if(n == k){ 
        for(int i =1;i<n;i+=2){
            if(cur != a[i]) break;
            cur++;
        }

    }else{ 
        int p = 1;
        int pos = 1;
        while(p < (n-k+1)+1){
            if(a[p] != 1){
                pos = 0;
                break;
            }
            p++;
        }
        if(pos) cur++;
    }
    cout << cur << '\n';

}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    int a[n];
    int b;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    cin >> b;
    int prev = INT_MIN;
    int pos = 1;
    for(int i = 0;i<n;i++){
        int p = b-a[i];
        if(a[i] < prev && p < prev){
            pos = 0;
            break;
        }
        if( p >= prev ){ 
            if(a[i] < prev) a[i] = p;
            else a[i] = min(p, a[i]);
        }
        prev = max(prev, a[i]);
    }

    cout << ((pos)?"YES":"NO") << '\n';


}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();

}

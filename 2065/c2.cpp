#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    int a[n];
    set<int> b;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    for(int i =0;i<m;i++){
        int k;
        cin >> k;
        b.insert(k);
    }
    int prev = INT_MIN;
    int pos = 1;
    for(int i = 0;i<n;i++){
        auto it = b.lower_bound(prev + a[i]);
        if(a[i] < prev && it == b.end()){
            pos = 0;
            break;
        }
        if( *it-a[i] >= prev ){ 
            if(a[i] < prev) a[i] = *it-a[i];
            else a[i] = min(*it-a[i], a[i]);
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

#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    
    cin >> n >> k;
    vector<int> a(n);

    for(int i =0;i<n;i++) cin >> a[i];
    set<int> s; 
    for(int i =0;i<n;i++){
        s.insert(a[i]);
    }
    if(s.size() > k){
        cout << -1 << '\n';
        return;
    }

    cout << int(k*n) << '\n';
    for(int i = 0;i<n;i++){
        int j = 0;
        for(int x:s){ 
            j++;
            cout << x << " ";
        }
        auto e=prev(s.end());
        for(int t=j;t<k;t++){
            cout << *e << " ";
        }
    }
    cout << '\n';
}


int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}

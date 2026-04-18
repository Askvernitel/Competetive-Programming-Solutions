#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, q;

    cin >> n >> q;
    vector<int> a(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int f[n];
    memset(f, 0, sizeof(f));

    f[0] = n-1;

    for(int i =0;i<n-1;i++){
        f[i+1] += (f[i] -1) + n-i-1; 
    }
    
    while(q--){
        int k;
        cin >> k;
        if(k > a[n-1]){ cout << 0 << " "; continue;}
        if(k < a[0]){cout << 0 << " "; continue;}
        auto it1 = upper_bound(a.begin(), a.end(), k);
        int cord = it1-a.begin();
        cout << f[cord] << " ";
    }
    cout << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}

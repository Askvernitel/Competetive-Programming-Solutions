#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<n;i++) cin >> b[i];
    set<int> s1, s2;
    for(int i =0;i<n;i++){
        s1.insert(a[i]);
        s2.insert(b[i]);
    }

    if((s1.size() <=2 && s2.size() <=1) || (s1.size() <=1 && s2.size()<=2)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

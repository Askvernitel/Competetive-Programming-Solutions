#include <bits/stdc++.h>

using namespace std;
void solve(){
    string s;

    cin >> s;
    int n = s.size();
    for(int i =0;i<n-1;i++){
        if(s[i] == s[i+1]){ 
            cout << 1 << '\n';
            return;
        }
    }

    cout << n << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

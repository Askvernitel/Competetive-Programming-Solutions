#include <bits/stdc++.h>

using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = s.size();

    for(int i =0;i<n-2;i++){
        cout << s[i];
    }
    cout << "i\n";
}
int main(){
    int tc;
    cin >> tc;

    while(tc--){
        solve();
    }
}

#include <bits/stdc++.h>

using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int cntN=0, cntY=0;
    for(int i =0;i<n;i++){
        if(s[i] == 'N'){
            cntN ++;
        }else{
            cntY++;
        }
    }

    if(cntY <= 1){ 
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

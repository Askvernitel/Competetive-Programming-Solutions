#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;
    int pos = 1;
    for(int i =0;i<n;i++){
        int p = 0;
        for(int j=0;j<n;j++){
            if(s2[i] == s1[j]){ 
                s1[j] = '#';
                p=1;
                break;
            }
        }
        if(!p){ 
            pos = 0;
        }
    }
    if(pos) {
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

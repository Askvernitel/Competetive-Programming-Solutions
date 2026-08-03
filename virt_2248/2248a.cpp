#include <bits/stdc++.h>
using namespace std;
void solve(){
        string s;
        cin >> s;
        int n = s.size();
        int idx_1 = -1;
        for(int i =0;i<n;i++){
                if(s[i] == '1'){
                        idx_1 = i;
                        break;
                }
        }
        int idx_0 = -1;

        for(int i =0;i<n;i++){
                if(s[i] == '0'){
                        idx_0 = i;
                        break;
                }
        }

        for(int i =0;i<n;i++){
                if(i == idx_0 || i == idx_1) continue;
                cout << s[i];
        }
        cout << '\n';
        
}
int main(){
        int tc;
        cin >> tc;
        while(tc--) solve();
}

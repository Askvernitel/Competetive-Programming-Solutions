#include <bits/stdc++.h>

using namespace std;
void solve(){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        for(int i =0;i<n;i++){
                if(i + k < n && s[i+k] == '1' && s[i] == '1'){
                        s[i] = '0';
                        s[i+k] = '0';
                }
                if(i + k < n && s[i+k] == '0' && s[i] == '1'){
                        s[i] = '0';
                        s[i+k] = '1';
                }
        }


        for(int i =0;i<n;i++){
                if(s[i] != '0'){
                        cout << "NO\n";
                        return;
                }
        }

        cout << "YES\n";

}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}

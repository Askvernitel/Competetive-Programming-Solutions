#include <bits/stdc++.h>

using namespace std;
void solve(){
        int n;

        cin >> n;

        char s[n+1];
        for(int i =0;i<n;i++){
                cin >> s[i];
        }
        s[n] = '#';
        int cnt = 0;
        for(int i =0;i<n;i++){
                if(s[i] != s[i+1]){
                        cnt++;
                }
        }
        int rem = 0;
        for(int i =1;i<n-1;i++){
                if(s[i] != s[i+1] && s[i] != s[i-1]){
                        rem = max(rem,1);
                        if(s[i+1] == s[i-1]){
                                rem = 2;
                        }
                }
        }

        cout << cnt - rem << '\n';
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}

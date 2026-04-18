#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt_R=0,cnt_B=0;
    int pos = 1;
    for(int i =0;i<n;i++){

        if(s[i] == 'B') cnt_B++;
        if(s[i] == 'R') cnt_R++;
        if((s[i] == 'W' || i+1 == n) && ((cnt_R >0 && cnt_B ==0) || (cnt_R == 0 && cnt_B > 0))){
            pos=0;
            break;
        }
        if(s[i] == 'W'){
            cnt_R = 0; cnt_B = 0;
        }
        
    }
    cout << ((pos)?"YES":"NO") << '\n';
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

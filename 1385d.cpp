#include <bits/stdc++.h>

using namespace std;
int rec(string s, int am, char needed){ 
    int m = s.size();
    if(m == 1){ 
        if(needed == s[0]) return am;
        
        return am + 1;
    }
    int cnt = 0;
    for(int i =m/2;i<m;i++){
        if(s[i] != needed){ 
            cnt++;
        }
    }
    int ans=INT_MAX;
    ans = min(rec(s.substr(0, m/2), am +cnt,char(needed+1 )),ans);
    cnt = 0;
    for(int i =0;i<m/2;i++){
        if(s[i] != needed){ 
            cnt++;
        }
    }

    ans = min(rec(s.substr(m/2, m/2), am+ cnt,char(needed+1)), ans);
    return ans;
}
void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    int ans = rec(s,0,'a');
    cout << ans<< '\n';

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

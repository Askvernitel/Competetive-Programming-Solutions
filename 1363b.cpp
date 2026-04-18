#include <bits/stdc++.h>

using namespace std;
void solve(){
    string s;

    cin >> s;
    int n = s.size();
    int cnt=0, ans=n;
    for(int i =0;i<n;i++){
        if(s[i] == '0'){cnt++;}
    } 
    int cnt1=cnt;
    ans = min(ans,cnt1);
    for(int i =0;i<n;i++){
        if(s[i] == '0') cnt1--;
        else cnt1++;
        ans = min(ans,cnt1);
    }
    int cnt2 =cnt;

    for(int i=n-1;i>=0;i--){
        if(s[i] =='0') cnt2--;
        else cnt2++;
        ans = min(ans,cnt2);
    }

    cout << ans << '\n';
    
}


int main(){
    ios_base::sync_with_stdio(false);
    int tc;

    cin >> tc;

    while(tc--) solve();
}

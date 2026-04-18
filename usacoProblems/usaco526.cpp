#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string s, c;
    cin >> s >> c;
    int n = s.size(), m = c.size();
    string ans="";
    for(int i =0;i<n;i++){
        ans += s[i];
        int p = m-1;
        int pos = 1;
        int t = ans.size();
        for(int j =t-1; j>=t-m;j--){
            if((j<0 && p >= 0) || (c[p] != ans[j])){ 
                pos = 0;
                break;
            }
            p--;
            if(p<0) break;
        }
        int sz = m;
        while(pos && sz--){ 
            ans.pop_back();
        }

    }
    cout << ans;
}

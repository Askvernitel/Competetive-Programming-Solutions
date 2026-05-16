#include <bits/stdc++.h>

using namespace std;
void solve(){
        string s, t;


        cin >> s >> t;

        sort(t.begin(), t.end());

        int m = t.size(), n = s.size();
        string ans;

        int cur = 0;
        map<char,int> st, ss;
        for(char ch : t){
                st[ch]++;
        }
        for(int i =0;i<n;i++){
                if(st[s[i]]){
                        ss[s[i]]++;
                        st[s[i]]--;
                }else{
                        cout << "Impossible\n";
                        return;
                }
        }
        s.push_back('z'+1);

        int p = 0;
        for(int i =0;i<m;i++){
                if(ss[t[i]]){
                        ss[t[i]]--;
                        continue;
                }
                if(t[i] < s[p]){ 
                        ans.push_back(t[i]);
                        continue;
                }

                while(t[i] >= s[p]){
                        ans.push_back(s[p]);
                        p++;
                }
                ans.push_back(t[i]);
        }
        while(p < n){ 
                ans.push_back(s[p]);
                p++;
        }
        cout << ans << '\n';
}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}

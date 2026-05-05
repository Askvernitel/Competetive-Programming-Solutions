#include <bits/stdc++.h>

using namespace std;
void solve(){
        string s, t;


        cin >> s >> t;

        sort(t.begin(), t.end());

//        cout << t << '\n';
        
        int m = t.size(), n = s.size();
        string ans;

        int cur = 0;
        map<char, int> remove_elements;
        for(int i =0;i<m;i++){
                while(cur < n && t[i] >= s[cur]){ 
                        ans.push_back(s[cur]);
                        remove_elements[s[cur]]++;
                        cur++;
                }
                if(remove_elements[t[i]]){
                        remove_elements[t[i]]--;
                        continue;
                }
                ans.push_back(t[i]);
        }
        string real_ans;
        for(int i =0;i<ans.size();i++){
                if(remove_elements[ans[i]]){
                        remove_elements[ans[i]]--;
                        continue;
                }
                real_ans.push_back(ans[i]);
        }
        cout << real_ans << '\n';

}
int main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}

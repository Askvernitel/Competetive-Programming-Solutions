#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    map<char, vector<int>> mp;

    int n = s.size();

    for(int i =1;i<n;i++){
        mp[s[i]].push_back(i);
    }
    int m = t.size();
    int sz = INT_MAX;
    string ans = "";
    for(int i =m-1;i>0;i--){
        if(mp[t[i]].size() != 0){ 
            int idx = mp[t[i]][0];
            string spref = s.substr(0,idx+1);
            string tsuf = t.substr(i+1, m);
            string res = spref + tsuf;
            if(res.size() < sz){ 
                sz = res.size();
                ans = res;
                break;
            }
        }
    }
    if(ans == "") ans = "-1";
    cout << ans;
}

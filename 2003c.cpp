#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    int a[26];
    memset(a, 0, sizeof(a));
    for(int i =0;i<n;i++) a[s[i]-'a']++;
    string ans = "";
    int last = -1;
    for(int i =0;i<n;i++){
        int prev = last;
        for(int j = 0;j<26;j++){
            if(a[j] != 0 && last != j){
                ans.push_back(j+'a');
                last = j;
                a[j]--;
                break;
            }
        }
        if(a[last] != 0 && prev == last){
            ans.push_back(last+'a'); 
            a[last]--;
        }
    }

    cout << ans << '\n';
}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

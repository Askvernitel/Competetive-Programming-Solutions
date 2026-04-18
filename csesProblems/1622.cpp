#include <bits/stdc++.h>

using namespace std;
int arr[26];
vector<string> ans;

void solve(string s, int n){
    if(s.size() >= n){ans.push_back(s); return;}
    for(int i =0;i<26;i++){
        if(arr[i]){
            char ch = 'a' + i;
            string t = s+ch;
            arr[i]--;
            solve(t, n);
            arr[i]++;
        }
    }

}
int main(){
    string s;

    cin >> s;
   
    for(int i =0;i<s.size();i++) arr[s[i] - 'a']++;

    solve("", int(s.size()));
    cout << ans.size() << '\n';
    for(int i = 0;i<ans.size();i++) cout << ans[i] << '\n';
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    string s;
    
    cin >> s;
    
    int n = s.size();
    int pos;
    cin >> pos; pos--;
    
    int prev_cnt=0;
    int cnt = n;
    int cur_cnt = n;
    int c = 0;
    while(pos+1 > cnt){ 
        cur_cnt--;
        c++;
        prev_cnt = cnt;
        cnt += cur_cnt;
    }
    vector<char> stack;
    for(int i =0;i<n;i++){
        while(c > 0 && !stack.empty() && stack.back() > s[i]){ 
            stack.pop_back();
            c--;
        }
        stack.push_back(s[i]);
    }
    while(c > 0){ 
        stack.pop_back();
        c--;
    }
    for(int i =0;i<stack.size();i++){
        if(prev_cnt == pos){cout << stack[i];break;}
        prev_cnt++;
    }



}
signed main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

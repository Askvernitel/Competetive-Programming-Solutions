#include <bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<int> positions;
    for(int i =0;i<n;i++){
        if(s[i] == '*') positions.push_back(i);
    }
    int m = positions.size();
    if(m<=1){cout << 0 << '\n'; return;}
    vector<int> prefd(m-1), sufd(m-1);
    for(int i =0;i<m-1;i++){
        int d = positions[i+1]-positions[i] -1 ;
        prefd[i] = d;
    }
    for(int i =m-1;i>0;i--){
        int d = abs(positions[i-1]-positions[i])-1; 
        sufd[i-1] = d;
    }
    
    for(int i =1;i<m-1;i++){
        prefd[i] = prefd[i-1] + prefd[i]*(i+1);
    }
    for(int i =m-3;i>=0;i--){
        sufd[i] = sufd[i+1] + sufd[i]*(m-1-i);
    }
/*    for(int i =0;i<m-1;i++){
        cout << prefd[i] << " ";
    }
    cout << '\n';
    for(int i =0;i<m-1;i++){
        cout << sufd[i] << " ";
    }*/
    int ans = min(prefd[m-2], sufd[0]);
    for(int i = 0;i<m-2;i++){
        ans = min(prefd[i]+sufd[i+1], ans);
    }
    cout << ans << '\n';
}


signed main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

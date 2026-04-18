#include <bits/stdc++.h>


using namespace std;


int mex(int cur, set<int>& s){ 
    while(s.find(cur+1) != s.end()){
        cur++;
    }
    return cur;
}
void solve(){
    int n;
    cin >> n;
    int p[n];
    for(int i =0;i<n;i++){
        cin >> p[i];
    }
    set<int> s;
    int cur = 0;
    for(int i =n-1;i>=0;i--){
        s.insert(p[i]);
        cur = mex(cur, s);
        if(cur == n-i && i != 0){ 
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){ 
    int tc;
    cin >> tc;
    while(tc--) solve();
}

#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> m;
    for(int i =0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
    }
    int mex =0;
    set<int> s;
    vector<int> ans;
    for(int i =0;i<n;i++){
        s.insert(a[i]);
        if(a[i] == mex){
            mex = a[i]+1;
            while(s.find(mex) != s.end()){
                mex++;
            }
        }
        if(m[mex] == 0 || i+1 == n){ 
            ans.push_back(mex);
            mex =0;
            s={};
        }
       
        m[a[i]]--;
    }
    cout << ans.size() << '\n';    
    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}
int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

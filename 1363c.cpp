#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    map<int, vector<int>> m;
    for(int i =0;i<n-1;i++){
        int u, v;
        cin >> u >> v;

        m[v].push_back(u);
        m[u].push_back(v);
    }
    
    int k =m[x].size();
    if(k <= 1){ 
        cout << "Ayush" << '\n';
        return;
    }

    if((n-1)%2){ 
        cout << "Ayush" << '\n';
    }else{
        cout << "Ashish" << '\n';
    }
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

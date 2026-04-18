#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, x;
    cin >> n >> x;

    int a[n];
    map<int,int> m;
    map<int,set<int>> g;
    for(int i =0;i<n;i++){cin >> a[i]; m[a[i]]++;}
    for(int i =0;i<n;i++){
        g[a[i]%x].insert(a[i]);
    }
    int cur = -1;
    for(auto &x: m){
        if(x.first == cur+1){
            cur++;
        }else{
            break;
        }
    }
    if(cur+1 >= x){
        int p = 1;
        while(p){
        int pos = 0;
        p = 0;
        for(auto x:g[(cur+1)%x]){
            if(x > cur+1) break;
            if(m[x] > 1 && x < cur+1){ 
                pos = 1;
                m[x]--;
                break;
            }
        }

        if(pos || m[cur+1]){
            //if(m[cur+1] == 0) m[(cur+1)%x]--;
            cur++;
            p = 1;
        }
        }
    }
    cout << cur+1 << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

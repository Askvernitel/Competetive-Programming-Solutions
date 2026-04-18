#include <bits/stdc++.h>

using namespace std;
int const N = 101;
int l[N];

int main(){
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int ord[m];
    map<int, vector<int>> mp;
    for(int i =0;i<m;i++){
        int num;
        cin >> num;
        ord[i]=num;
    } 
    for(int i =0;i<m;i++){
        for(int j=i-1;j>=0;j--){
            mp[ord[i]].push_back(ord[j]);
        }
    }
    int s = 0, ans = -1;
    for(int i =0;i<k;i++){
        int p, c;
        cin >> p >> c;
        l[c] = p;
        if(p == 1){s = 1; ans = c;}
    }
    if(s){cout << ans; return 0;}
    for(int i =1;i<=n;i++){
        if(l[i]) continue;
        bool pos = 1;
        for(int j =i;j<=n;j++){
            if(l[j] && j == i) pos = 0;
            if(l[j]){
                int v = mp[l[j]].size()-1;
                int t = j-1;
                while(v>=0){
                    if(mp[l[j]][v] == -1){v--; continue;}
                    l[t] = mp[l[j]][v];
                    if(t == i) pos = 0;
                    v--;
                    t--;
                }
                for(int x:mp[l[j]]){
                    if(x == -1) continue;
                    for(auto &it:mp){
                        for(int c = 0; c<it.second.size();c++){
                            if(it.second[c] == x){
                                it.second[c] = -1;
                            }
                        }
                    }
                }
            }
            if(!pos) break;
        }
        if(pos){ans = i; break;}
    }

    cout << ans;
}


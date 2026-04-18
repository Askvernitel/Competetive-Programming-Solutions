#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> a[n];
    map<string, vector<set<string>>> g;
    for(int i =0;i<n;i++){
        int k; cin >> k;
        for(int j =0;j<k;j++){
            string s;
            cin >> s;
            a[i].push_back(s);
        }
        set<string> u;
        for(int j =0;j<k;j++){
            u = {};
            for(int t = 0;t<k;t++){
                if(t == j) continue;
                u.insert(a[i][t]); 
            }
            g[a[i][j]].push_back(u);
        }

    }
    int pos = 1;
    for(int i = 0;i<n;i++){
        int found = 0;
        for(string s:a[i]){ 
            for(set<string> t: g[s]){ 
                int root = 1;
                for(string p:a[i]){ 
                    if(p == s) continue;
                    if(t.find(p) != t.end()){ 
                        root = 0; break;
                    }
                }
                if(root && found) pos = 0;
                if(root){found=1; break;}
            }
        }
    }
    if(pos){ 
        cout << "yes";
    }else {
        cout << "no";
    }


}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    map<int,int> m;
    map<int, vector<int>> p;
    set<int> r, w;
    for(int i=0;i<n;i++){
        m[a[i]]+=a[i];
    }
    
    for(auto &x:m){ 
        p[x.second].push_back(x.first);
    }
    int ans = 0;
    auto it = prev(p.end());
    int j = 0;
    while(r.size() != m.size()){
        while(it != prev(p.begin())){
            int f = 0, res=-1;
            for(int i = 0;i<(*it).second.size();i++){
                if(r.find((*it).second[i]) == r.end()){
                    f = 1;
                    res = i;
                    break;
                }
            }
            if(f){ans+=(*it).first; r.insert((*it).second[res]); break;}
            it--;
        }

        while(r.find(a[j]) != r.end() && j<n) j++;
        if(j < n) r.insert(a[j]);
    }

    cout << ans;


} 


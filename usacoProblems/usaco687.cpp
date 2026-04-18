#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int n;

    cin >> n;
    string names[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    //if(n == 1){cout << "tie" <<'\n'; return 0;}
    map<string, int> m;

    for(int i =0;i<7;i++){
        m[names[i]] = 0;
    }
    for(int i =0;i<n;i++){
        string s;
        int M;
        cin >> s >> M;

        m[s]+=M;
    }
    map<int, vector<string>> t;
    for(auto &x:m){
        t[x.second].push_back(x.first);
    }
    
    string ans ="";
    int p = 0;
    for(auto it = t.begin(); it != t.end(); it++){
        
        if(p == 1 && (it->second).size() == 1){ans = (it->second)[0]; break;}
        else ans = "Tie";
        p++;
    }
    cout << ans << '\n';
}

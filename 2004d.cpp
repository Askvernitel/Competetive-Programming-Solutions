#include <bits/stdc++.h>
 
using namespace std;
int b(vector<int>& a, int x){
    int n = a.size();
    int l = 0, r = n-1;
    while(l < r){
        int m = (l+r)/2;

        if(x > a[m]){
            l=m+1;
        }else{
            r=m;
        }   

    }

    return r;
    

}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<string> cities(n);
    map<string, vector<int>> portals;
    for(int i =0;i<n;i++){
        string city;
        cin >> city;
        cities[i] = city;
        portals[city].push_back(i);
    }

    while(q--){
        int from, to;
        cin >> from >> to;
        from--; to--;
        string f = cities[from], t = cities[to];
        int cost = INT_MAX;
        for(auto &x: portals){
            string str = x.first;
            int pos1=0, pos2=0;
            for(int i=0;i<2;i++){
                if(str[i] == f[0] || str[i] == f[1]) pos1 = 1;
                if(str[i] == t[0] || str[i] == t[1]) pos2 = 1;
            }
            if(x.second.size() == 0) continue;
            if(pos1 && pos2){

                int p = b(x.second, from);
                
                cost = min(cost, abs(x.second[p]-from) + abs(x.second[p]-to));

                if(p < x.second.size() -1){
                   cost = min(cost, abs(x.second[p+1] - from) + abs(x.second[p+1]-to));
                }
                if(p > 0){
                    cost = min(cost, abs(x.second[p-1] - from) + abs(x.second[p-1]-to));
                }

            }
        }
        if(cost == INT_MAX) cost = -1;
    
        cout << cost << '\n';
    }


    

}

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();

}

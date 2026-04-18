#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    int n, m, d, s;
    cin >> n>> m >> d >> s;

    set<int> milks[m+1]; 
    vector<pair<int,int>>people[n+1];
    for(int i =0;i<d;i++){
        int p, m, t;
        cin >> p >> m >> t;
        people[p].push_back({m, t});
        milks[m].insert(p);
    }
    vector<int> sick(n+1, 0);
    for(int i=0;i<s;i++){
        int p, t;
        cin >> p >> t;
        sick[p] = t;
    }
    int ans = 0;
    for(int i =1;i<=m;i++){
        int pos = 1;
        for(int j =1;j<n+1;j++){
            if(sick[j] == 0) continue;
            bool drank = 0;
            for(int k = 0;k<people[j].size();k++){
                if(people[j][k].first == i && people[j][k].second < sick[j]){
                    drank = 1;
                    break;
                }
            }
            if(!drank){pos = 0; break;}
        }
        if(!pos) continue;
        ans = max(ans, int(milks[i].size()));

    }
    cout << ans;
}

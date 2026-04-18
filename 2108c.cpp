#include <bits/stdc++.h>

using namespace std;

int n;
int a[200000];
void add(priority_queue<pair<int,int>>& pq,set<int>& vis, pair<int,int> p){
    vis.insert(p.second);
    if((vis.find(p.second-1) == vis.end()) && p.second-1 >= 0){
        pq.push({a[p.second-1], p.second-1});
        vis.insert(p.second-1);
    }

    if((vis.find(p.second+1) == vis.end()) && p.second+1 < n){
        pq.push({a[p.second+1], p.second+1});
        vis.insert(p.second+1);
    }
}
int cnt = 0;
void solve(){
    cin >> n;
    map<int,set<int>> m={};
    for(int i =0;i<n;i++){
        cin >> a[i];
        m[a[i]].insert(i);
    }
    int ans = 0;
    set<int> vis = {};
    priority_queue<pair<int,int>> pq1={};
    while(!m.empty()){
        if(pq1.empty()){
            auto p1 = m.rbegin();
            ans++;
            add(pq1, vis, {p1->first, *p1->second.begin()});
            p1->second.erase(p1->second.begin());
            if(p1->second.empty()){
                m.erase(p1->first);
            }
            continue;
        }
        pair<int,int> curmax = pq1.top();
        auto p1 = m.rbegin();
        if(curmax.first != p1->first){
            ans++;
            pair<int,int> p2 = {p1->first, *p1->second.begin()};
            add(pq1, vis, p2);
            p1->second.erase(p1->second.begin());
            if(p1->second.empty()){
                m.erase(p1->first);
            }
        }else{
            pair<int,int> p2 = pq1.top();
            pq1.pop();
            add(pq1, vis,p2);
            p1->second.erase(p2.second);
            if(p1->second.empty()){
                m.erase(p1->first);
            }
        }
    }
    cout << ans << endl;
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

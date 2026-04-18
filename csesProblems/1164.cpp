#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<pair<int, pair<int,int>>> custs;

    for(int i =0;i<n;i++){
        int a, b;
        cin >> a >> b;
        custs.insert({a,{b, i}});
    }
    priority_queue<pair<int,int>> deps;
    priority_queue<int> rooms;
    int ans[n];
    int maxv = 0;
    for(pair<int,pair<int,int>> cust: custs){ 
        while(!deps.empty() && abs(deps.top().first) < cust.first){
            rooms.push((int)deps.top().second);
            deps.pop();
        }
        int room;
        if(rooms.empty()){
            room = deps.size()+1;
        }else{
            room = rooms.top();
            rooms.pop();
        }
        maxv = max(room, maxv);
        deps.push({-cust.second.first, room});
        ans[cust.second.second] = room;
    }

    cout << maxv << '\n';
    for(int i =0;i<n;i++){
        cout << ans[i] << " ";
    }




}

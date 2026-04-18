#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define inf 2e8
int n;
void search_put(vector<pair<int,int>>& all, vector<int>& ans, pair<int,int> x, int value){
    for(int i =0;i<n;i++){
        if(all[i].F == x.F && all[i].S == x.S){
            ans[i] = value;
            return;
        }
    }
}
int main(){
    cin >> n;
    vector<pair<int,int>> E, N; 
    vector<pair<int,int>> all(n);
    for(int i =0;i<n;i++){
        char dir;
        int x, y;
        cin >> dir >>  x >> y;

        if(dir == 'N'){ 
            N.push_back({x,y});
        }else{
            E.push_back({x,y});
        }
        all[i] = {x,y};
    }
    sort(E.begin(), E.end(), [&](pair<int,int> a, pair<int,int> b){return a.S < b.S;});
    sort(N.begin(), N.end());

    vector<int> ans(n, INT_MAX);
    for(int i=0;i<E.size();i++){
        pair<int,int> cur_cow = E[i];
        
        for(int j=0;j<N.size();j++){
            if(N[j].F == -1) continue;
            pair<int,int> cow = N[j];
            if(cow.S < cur_cow.S && cow.F > cur_cow.F && cow.F-cur_cow.F < cur_cow.S - cow.S){
                search_put(all, ans, N[j], cur_cow.S-cow.S);
                N[j].F = -1;
            }
 
            if(cow.S < cur_cow.S && cow.F > cur_cow.F && cow.F-cur_cow.F > cur_cow.S - cow.S){ 
                search_put(all, ans, E[i], cow.F-cur_cow.F);
                break;
            }
       }
    }
    for(int a:ans){
        cout << ((a == INT_MAX)?"Infinity": to_string(a)) << '\n'; 
    }

}

#include <bits/stdc++.h>

using namespace std;
int vis[10001];
set<int> p;
int a[10001];
int ans =0;
void dfs(int cur){ 
    if(!vis[cur]){ 
        vis[cur] =1;
        p.insert(cur);
        dfs(a[cur]-1);
    }else if(p.find(cur) != p.end()){
        ans++;
    }
} 
int main(){ 
    int n;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }


    for(int i =0;i<n;i++){

        dfs(i);
        p={};
    }
    cout << ans <<'\n';
    
}

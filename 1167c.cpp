#include <bits/stdc++.h>

using namespace std;
set<int> groups[500001];
int n,m;
set<int> p[500001];
void dfs(int cur){ 
    for(int i =0;i<m;i++){ 
        
    }
}
int main(){
    cin >> n >> m;
    
    for(int i =0;i<m;i++){
        int k;
        cin >> k;
        for(int j =0;j<k;j++){
            int num;
            cin >> num;
            groups[i].insert(num);
        }
    }

    dfs(1);
}

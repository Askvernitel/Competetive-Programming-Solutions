#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out","w", stdout);
    int n, m;
    cin >> n >> m;
    set<int> a[n];
    for(int i = 0;i<m;i++){
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        a[v1].insert(v2);
        a[v2].insert(v1);
    }
    int ans[n];
    memset(ans,0,sizeof(ans));
    for(int i =0;i<n;i++){
        int pos[5];
        memset(pos,0,sizeof(pos));
        
        for(int x:a[i]){
            pos[ans[x]]++;
        }
        for(int j=1;j<5;j++){
            if(pos[j] != 0) continue;
            ans[i] = j;
            break;
        }
    }
    for(int i =0;i<n;i++){
        cout << ans[i];
    }
}

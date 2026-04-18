#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int d[n],l[n],r[n];
    for(int i=0;i<n;i++){
        cin >> d[i];
    }
    for(int i=0;i<n;i++){
        cin >> l[i] >> r[i];
    }
    int c1[n], c2[n];
    memset(c1,-1,sizeof(c1));
    int mn_cur=0;
    int mx_cur=0;
    int cnt = 0;
    bool pos = 1;
    set<int> inds;
    for(int i=0;i<n;i++){
        if(d[i]!=-1){
            mx_cur+=d[i];
            mn_cur+=d[i];
        }else{ 
            mx_cur++;
            inds.insert(i);
        }
        if(min(r[i],mx_cur)-max(l[i],mn_cur) < 0){
            pos=0;
            break;
        }
        int u=max(mx_cur-r[i],0);
        mx_cur=min(mx_cur,r[i]);
        while(u--){ 
            auto it = inds.begin();
            int x = *it;
            inds.erase(it);
            c1[x]=0;
        }
        int t =max(l[i]-mn_cur,0);
        mn_cur=max(l[i],mn_cur);
        while(t--){
            auto it = inds.begin();
            int x=*it;
            inds.erase(it);
            c1[x]=1;
        }
    }
    if(!pos){ 
        cout << -1 << '\n';
        return;
    }
    int ans[n];

    for(int i =0;i<n;i++){
        if(c1[i] == -1 && d[i] == -1){ 
            ans[i]=0;
        }else if(c1[i] != -1){ 
            ans[i]=c1[i];
        }else{
            ans[i]=d[i];
        }
    }
    for(int i =0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

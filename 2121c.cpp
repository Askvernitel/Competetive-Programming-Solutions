#include <bits/stdc++.h>


using namespace std;
int n, m;
void op(vector<vector<int>>& a, int l, bool row, int ur){
    if(row) {
        for(int i=0;i<m;i++){
            if(i == ur){ 
                continue;
            }
            a[l][i]--;
        }
    }else{
        for(int i=0;i<n;i++){
            if(ur == i){ 
                continue;
            }
            a[i][l]--;
        }
    }
}
int cnt(vector<vector<int>>& a, int l, bool row, int maxv){
    int res = 0;
    if(row) {
        for(int i=0;i<m;i++){
            if(maxv == a[l][i]){
                res++;
            }
        }
    }else{
        for(int i=0;i<n;i++){
            if(maxv == a[i][l]){
                res++;
            }
        }
    }
    return res;
}
int maxG(vector<vector<int>>& arr){
    int maxv = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxv = max(arr[i][j], maxv);
        }
    }
    return maxv;
}

void solve(){
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int maxv = 0;
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> a[i][j];
        }
    }
    maxv= maxG(a);
    int t = 0;
    int r = 0;
    int rr = 0;
    int cc =0;
    for(int i=0;i<n;i++){
        int k = cnt(a,i,true,maxv);
        if(k>t){
            t=k;
            r=i;
            rr=1;
        }
    }
    //op(a, r, true, -1);
    
    //maxv=maxG(a);
    int p =0;
    int c=0;
    for(int i=0;i<m;i++){
        int k = cnt(a,i,false,maxv);
        if(k>t){ 
            t=k;
            c=i;
            cc=1;
            rr=0;
        }
    }
    if(rr){
        op(a, r, true, -1);
        maxv= maxG(a);
        p =0;
        c=0;
        for(int i=0;i<m;i++){
            int k = cnt(a,i,false,maxv);
            if(k>p){ 
                p=k;
                c=i;
            }
        }
        op(a,c,false, r);
    }else{
        op(a, c, false, -1);
        maxv= maxG(a);
        p =0;
        r=0;
        for(int i=0;i<n;i++){
            int k = cnt(a,i,true,maxv);
            if(k>p){
                p=k;
                r=i;
            }
        }
        op(a,r,true, c);
    }

    cout << maxG(a) << '\n';
    
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

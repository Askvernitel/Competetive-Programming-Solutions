#include <bits/stdc++.h>
using namespace std;

struct SegTree{ 
    int size;
    vector<int> p;
    void init(int n){
        int t = 1;
        while(t <= n) t*=2;
        size = t;
        p.assign(2*size, 0);
    }

    void set(int s, int v){ 
        set(s, 0, size, v, 0);
    }
    void set(int i, int l, int r,int v, int cur){ 
        if(r-l <= 1){
            p[cur] = v;
            return;
        }
        int m = (l + r)/2;
        if(i < m){ 
            set(i, l, m, v, 2*cur+1);
        }else{
            set(i, m, r, v, 2*cur+2);
        }
        p[cur] = p[2*cur+1] + p[2*cur+2];
    }

    int get(int l, int r, int lt, int rt, int cur){ 
        if(rt <= l || lt >= r){ 
            return 0;
        }

        if(rt >= r && lt <= l){
            return p[cur];
        }
        int m = (l+r)/2;
        return get(l, m, lt, rt, 2*cur+1) + get(m, r, lt, rt, 2*cur+2);
    }
    int get(int l){
        return get(0,size, l, size, 0);
    }

};

void solve(){

    int n;
    cin >> n;
    int p[n];
    SegTree s = {};
    s.init(n);
    for(int i =0;i<n;i++){
        cin >> p[i];
        s.set(i+1, 1);
    }
    //cout << s.get(4) << '\n';
    //s.set(5, 0);
    //cout << s.get(4) << '\n';
    bool pos = 1;


    int minv = INT_MAX;
    for(int i =0;i<n;i++){
        if(s.get(p[i]) == 1 && p[i] <= minv){
            pos=0;
            break;
        }
        minv = min(minv, p[i]);
        s.set(p[i],0);
    }
    if(!pos){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

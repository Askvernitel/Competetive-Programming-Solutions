#include <bits/stdc++.h>

using namespace std;
int n, m, k;
bool c(vector<int> p, vector<int> h){
    vector<int> cp(n, -1);

    for(int i =0;i<n;i++) if(p[i] != -1) cp[p[i]] = i;

    int t = 0;

    for(int i =0;i<n && t<m;i++){
        if(cp[h[t]] != -1){
            
            if(i > cp[h[t]]) return false;
            
            i = cp[h[t]];
    
        }else{
            while(i<n && p[i] != -1) i++;
//            if(i >= n) return false;

            p[i] = h[t];
        }
        t++;

    }
    return true;

}
int main(){
    //int n, m, k;
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);    
    cin >> n >> m >> k;
    vector<int> p(n, -1);
    vector<int> h(m);
    for(int i =0;i<m;i++){int c; cin >> c; c--; h[i] = c;}
    
    for(int i =0;i<k;i++){
        int c, t;
        cin >> c >> t;
        c--; t--;
        p[t] = c;
        if(c == 0){cout << t+1; return 0;}
    }

    for(int i =0;i<n;i++){
        if(p[i] == -1){
            p[i] = 0;
            if(c(p, h)){
                cout << i + 1;
                break;
            }
            p[i] = -1;            
        }
    }

}

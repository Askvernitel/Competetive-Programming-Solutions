#include <bits/stdc++.h>

using namespace std;
void findPdivs(int num, map<int,int>& m){
    int pdiv = 2;
    while(num > 1){ 
        if(!(num%pdiv)){
            m[pdiv]++;
            num/=pdiv;
        }else{
            if(pdiv == 2) pdiv++;
            else pdiv+=2;
        }
    }
}
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
        
    int pos = 1;
    map<int,int> m1, m2, lim;
    for(int i =2;i<n;i++){
        int v1 = a[i-1], v2 = a[i-2];
        findPdivs(v1, m1);
        findPdivs(v2, m2);
        
        for(auto &[x,y]:m2){
            if(m1[x] < y) lim[x]=m1[x];
        }
        m1={};
        findPdivs(a[i], m1);
        for(auto &[x,y]:m1){
            if(lim.find(x) != lim.end() && y > lim[x]){
                pos = 0;
                break;
            }
        }
        m1={}; m2={}; lim={};
        if(!pos) break;
    }
    cout << ((pos)?"YES":"NO") << '\n';
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

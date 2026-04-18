#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int a,b,c;
    cin >> a >> b >> c;
    int m;
    cin >> m;

    pair<int, string> p[m];
    for(int i=0;i<m;i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p, p+m);
    int amount =0, price=0;
    for(int i=0;i<m;i++){
        if(p[i].second == "USB" && a > 0){
            amount++;
            price+=p[i].first;
            a--;
        }else if(p[i].second == "PS/2" && b > 0){
            amount++;
            price+=p[i].first;
            b--;
        }else if(c > 0){
            amount++;
            price+=p[i].first;
            c--;
        }
    }
    cout << amount << " " << price << '\n';
}

#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int k;
void calc(int x, vector<int>& vx, map<int,int>& mx){ 
    int d=2;
    while(x > 1){ 
        if(x%d){ 
            if(d==2) d++;
            else d+=2;
        }else{ 
            vx.push_back(d);
            mx[d]++;
            x/=d;
        }
    }
}
pair<int,int> real(pair<int,int> p){ 
    return {p.F*-1, p.S};
}
int mult(map<int,int>& x){
    if(x.empty()) return 0;
    int res = 1;
    for(auto &[c,d]:x){ 
        res*=pow(c,d);
    }
    return res;
}
int mults(set<int> & x){
    if(x.empty()) return 0;
    int res = 1;
    for(int t:x){
        res*=t;
    }
    return res;
}
int rec(map<int,int> x){ 
    if(x.empty()) return 0;
    if(mult(x) <= k){
        return 1;
    }
    map<int,int> l,r;
    set<int> lf1,lf2, sf1, sf2, ml;
    for(auto &[c,d]:x){ 
        l[c]=d/2;
        r[c]=d/2;
        if(d%2){ 
            lf1.insert(c);
            ml.insert(c);
        }
    }
    int mncur=INT_MAX;
    
    for(int t:ml){ 
        int mn=max(mults(lf1), mults(lf2));
        if(mncur > mn){
            mncur=mn;
            sf1=lf1;
            sf2=lf2;
        }
        lf1.erase(t);
        lf2.insert(t);
    }
    for(int t:sf1) l[t]++;
    for(int t:sf2) r[t]++;
    
    return rec(l) + rec(r);
}
void solve(){
    int x,y;
    cin >> x >> y >> k;

    vector<int> vx, vy;
    map<int,int> mx, my;
    calc(x,vx,mx);
    calc(y,vy,my);
    int ans = 0;
    for(auto &[c,d]:my){ 
        if(mx[c] - d > 0){ 
            ans+=mx[c]-d;
            mx[c]=0;
            continue;
        }
        mx[c]-=d;
    }
    map<int,int> r, a;
    priority_queue<pair<int,int>> pr, pa;
    for(auto &[c,d]:mx){ 
        if(d < 0){ 
            r[c]=abs(d);
            pr.push(real({c, abs(d)}));
        }else{
            a[c]=d;
            pa.push(real({c, d}));
        }
    }

/*
    for(auto &[c,d]:r) {
        cout << c << ' ';
    }
    cout << '\n';
    for(auto &[c,d]:a) {
        cout << c << ' ';
    }
    cout << '\n';*/
    int found = 0;
    auto it1=r.rbegin();
    while(it1 != r.rend()){ 
        if(it1->S != 0 && it1->F > k){
            found=1;
            break;
        }
        if(it1->S != 0) break;
        it1--;
    }
    if((!r.empty() && found)){ 
        cout << -1 << '\n';
        return;
    }
    auto it2=a.rbegin();
    while(it2 != a.rend()){
        if(it2->S != 0 && it2->F > k){
            found=1;
            break;
        }
        if(it2->S != 0) break;
        it2--;
    }
    if((!a.empty() && found)){
        cout << -1 << '\n';
        return;
    }

    cout << rec(r) + rec(a) << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

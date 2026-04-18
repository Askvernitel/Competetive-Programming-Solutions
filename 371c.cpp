#include <bits/stdc++.h>
#define int long long
using namespace std;
int nb,ns,nc;
int pb,ps,pc;
int amb=0, ams=0, amc=0;
int rb;
bool f(int x){ 
    int cost = ((amb*pb) + (ams*ps) + (amc*pc))*x;
    if(amb) cost -= min(amb*x*pb, (nb*pb));
    if(ams) cost -= min(ams*x*ps, (ns*ps));
    if(amc) cost -= min(amc*x*pc, (nc*pc));
//    cout << cost << ' ';
    return cost > rb;    
}
signed main(){
    string s;
    cin >> s;
    for(char ch:s){ 
        if(ch == 'B'){
            amb++;
        }else if(ch =='C'){ 
            amc++;
        }else{
            ams++;
        }
    }


    cin >> nb >> ns >>nc;

    cin >> pb >> ps >> pc;
    
    cin >> rb;
    
    int l = 0, r=1;
    while(!f(r)) r*=2;
    while(r-l>1){ 
        int m=(l+r)/2;
        if(f(m)) r =m;
        else l = m;
    }

    cout << l << '\n';
}   

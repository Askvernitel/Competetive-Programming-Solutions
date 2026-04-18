#include <bits/stdc++.h>

using namespace std;
int main(){
    int tc;

    cin >> tc;

    multiset<int> lo, hi;
    while(tc--){
        char o;
        int l, r;
        
        cin >> o >> l >> r;

        if(o == '+'){
            lo.insert(l);
            hi.insert(r);
        }else{ 
            lo.erase(lo.find(l));
            hi.erase(hi.find(r));
        }
        if(lo.size() <= 1 || hi.size() <= 1){ 
            cout << "NO\n";
            continue;
        }
        int p1 = *hi.begin();
        int p2 = *prev(lo.end());
        //cout << p1 << " " << p2;
        auto it1 =lo.upper_bound(p1); 

        if(it1 == lo.end()){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        }
    
}

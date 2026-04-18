#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k, q;

    cin >> n >> k >> q;
    int a[k], b[k];
    for(int i = 0;i<k;i++) cin >> a[i];
    for(int i = 0;i<k;i++) cin >> b[i];

    map<int, int> m;

    for(int i =0;i<k;i++) m[a[i]] = b[i];
    
    //auto t = m.begin()--;
    while(q>0){
        //cout << "inp";
        int d;
        cin >> d;

        auto it = m.lower_bound(d);
        //assert((++it) == m.begin());
        //assert(it == t);
   //     cout << it->second << '\n';
 //       break;
        if(it != m.begin()){ 
            auto p2 = (it), p1 = (--it);
            //cout << p1->first << " " << p2->first <<  " ";
            double v = double(double(p2->first - p1->first)/double(p2->second - p1->second));
            //cout << "V: " << v;
            double dt = (double(d)- double(p1->first));
            double ans = dt/v;
            double t = p1->second;
            cout << int(ans + t)  << " "; 
        }else{
            //cout << "EEE";
            it = m.begin();
            //cout << it->first << " " << it->second << " ";
            double v = double(double(it->first)/double(it->second));
            double dt = d;
//            cout << v << " " << dt << " ";
            double ans = dt/v;
            cout << int(ans) << " ";
        }
        q--;
    }
    cout << endl;
}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}

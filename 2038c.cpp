#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    map<int,int> m;
    for(int i =0;i<n;i++) m[a[i]]++;
    int c = 0;
    vector<int> pts;
    for(auto &x: m){
        while(x.second >= 2 && c < 2){
            x.second -=2;
            pts.push_back(x.first);
            c++;
        }
        if(c > 1) break;
    }
    auto it = m.end();
    int k =0;
    do{
        it--;
        while((*it).second >= 2 && k < 2){
            (*it).second-=2;
            pts.push_back((*it).first);
            k++;
        }
 
        if(k > 1) break;
    }while(it != m.begin());
    if(k+c < 4){
        cout << "NO" << '\n';
        return;
    }

    sort(pts.begin(), pts.end());

    cout << "YES" << '\n';

    cout << pts[0] << " " << pts[3] << " " << pts[0] << " " << pts[1] << " " << pts[2] << " " << pts[3] << " " <<  pts[2] << " " << pts[1];
    cout << endl; 
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}

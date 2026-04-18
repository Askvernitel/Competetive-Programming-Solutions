#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    map<int, set<int>> m;
    for(int i =0;i<n;i++){
        cin >> a[i];
        m[a[i]].insert(i);
    }
    vector<pair<int,int>> ans;
    for(int i =n-1;i>=0;i--){
        if(a[i] == 0){  
            if(m[1].size() != 0 && m[2].size() != 0){

                int p1=*m[1].begin();
                int p2=*m[2].begin();

                swap(a[i], a[p1]);
                swap(a[i], a[p2]);
                m[2].erase(p2);
                ans.push_back({i, p1});
                ans.push_back({i, p2});
                m[1].erase(p1);
                m[1].insert(p2);
                m[0].erase(i);
                m[0].insert(p1);
            }else if(m[1].size() != 0){ 
                int p1=*m[1].begin();
                swap(a[i], a[p1]);
                ans.push_back({i, p1});
                m[1].erase(p1);
                m[0].erase(i);
                m[0].insert(p1);
            }

        }else if(a[i] == 1){ 
            if(m[2].size() != 0){ 
                int p2=*m[2].begin();
                swap(a[i], a[p2]);
                ans.push_back({i, p2});
                m[2].erase(p2);
                m[1].erase(i);
                m[1].insert(p2);
            }
            m[1].erase(i);
        }else{ 
            m[2].erase(i);
        }
            
        
           
    }
    cout << ans.size() << '\n';
    for(auto &[a, b]: ans){ 
        cout << a+1 << " " << b+1 << '\n';
    }
}
int main(){
    int tc;
    cin >> tc;


    while(tc--) solve();
}

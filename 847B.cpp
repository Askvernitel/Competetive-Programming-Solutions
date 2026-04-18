#include <bits/stdc++.h>

using namespace std;
int marked[200001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];
    map<int, int> m;
    for(int i =0;i<n;i++) m[a[i]]=i;
    for(int i =0;i<n;i++){
        if(!marked[i]){ 
            marked[i] = 1;
            auto it = m.upper_bound(a[i]);
            map<int, int> mr;
            while(it != m.end()){
                if((*it).second > i && !marked[(*it).second]) mr[(*it).second] = (*it).first;
                it++;
            }
            int prev_max = a[i];
            m.erase(a[i]);
            cout << prev_max << " "; 
            for(auto &x: mr){
                if(x.second > prev_max){ 
                    prev_max = x.second;
                    cout << prev_max << " ";
                    m.erase(x.second);
                    marked[x.first]=1;
                }
            }
            cout << '\n';
        }
    }


}

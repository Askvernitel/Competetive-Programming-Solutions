#include <bits/stdc++.h>

using namespace std;
int bs(int x, vector<int>& vec, int nc){ 
    int n = vec.size();
    int l = -1, r = n;
    while(r-l>1){ 
        int m = (r+l)/2;
        if(x <= vec[m]){ 
            r = m;
        }else{ 
            l = m;
        }
    }
    if(l == -1){ 
        if(vec[r]== nc){ 
            return abs(vec[r+1] - x);
        }
        return abs(vec[r]-x);
    }
    if(r == n){ 
        if(vec[l] == nc){
            return abs(vec[l-1] - x);
        }
        return abs(vec[l]-x);
    }
    if(vec[r] == nc && r+1 == n){
        return abs(vec[l]-x);
    }
    if(vec[l] == nc && l-1 < 0){ 
        return abs(vec[r]-x);
    }
    return min(abs(((vec[r]==nc)?vec[r+1]-x:vec[r]-x)), abs((vec[l]==nc)?vec[l-1]-x:vec[l]-x)) ;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    if(n%2){ 
        cout << 0 << '\n';
        return 0;
    }
    map<int, vector<int>> m;
    for(int i =0;i<n;i++){ 
        m[a[i]].push_back(i);
    }
    
    int ans = INT_MAX;
    for(int i =0;i<n;i++){
        int idx=(n-i-1);
        if((int)m[a[i]].size() == 1) continue;
        ans = min(ans, bs(idx, m[a[i]], i));
    }
    cout << ans << '\n';
}

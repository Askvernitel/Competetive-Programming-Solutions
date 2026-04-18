#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    unordered_set<int> s;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i =0;i<n;i++){        
        vector<int> v = {};
        int found = 0;
        for(int j=0;j<i;j++){
            if(s.find(a[i]-a[j]) != s.end() && !found){
                ans++;
                found = 1;
            }
            v.push_back(a[i] + a[j]);
        } 
        for(int x:v){
            s.insert(x);
        }
        s.insert(2*a[i]);
    }
    cout << ans;
}

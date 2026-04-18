#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    
    vector<int> greater, lower, a;
    for(int i =0;i<n;i++){
        char s;
        int p;
        cin >> s >> p;
        if(s == 'L'){
            lower.push_back(p);
        }else{
            greater.push_back(p);
        }
        a.push_back(p);
    }
    int r = greater.size(), k = lower.size();
    
    int ans = INT_MAX;
    for(int i =0;i<n;i++){
        int pos = a[i];
        int liars = 0;
        for(int j =0;j<r;j++){
            if(pos < greater[j]) liars++;
        }
        for(int j =0;j<k;j++){
            if(pos > lower[j]) liars++;
        }
        ans = min(liars,ans);
    }
    cout << ans << '\n';
}   

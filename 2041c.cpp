#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int p = n*n*n;
    vector<int> a[p];
    for(int i =0;i<p;i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[i].push_back(x); a[i].push_back(y); a[i].push_back(z);
    }




}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;

    cin >> n >> x;

    int a[n];

    for(int i =0;i<n;i++) cin >> a[i];



    map<int, vector<int>> m;
    for(int i =0;i<n;i++){m[a[i]].push_back(i);}

    
    sort(a, a + n);
    int l = 0, r = n-1;
    
    while(l < r){
        if(a[l] + a[r] > x){
            r--;
        }else if(a[l] + a[r] < x){
            l++;
        }else{
            break;
        }
    }
    if(r <= l){cout << "IMPOSSIBLE"; return 0;}
    int p1, p2;
    if(a[r] == a[l]){
        p1 = m[a[l]][0];
        p2 = m[a[r]][1];
    }else{
        p1 = m[a[l]][0];
        p2 = m[a[r]][0];
    }

    cout << p1+1 << " " << p2+1;
}

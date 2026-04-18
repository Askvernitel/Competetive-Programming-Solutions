#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;

    cin >> n >> x;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    map<int, vector<int>> m;
    for(int i =0;i<n;i++){
        m[a[i]].push_back(i+1);
    }

    sort(a,a+n);

    int pos = 0, fr = -1, sc=-1,th=-1;
    for(int i =0;i<n;i++){
        int s = x - a[i];
        int l = i+1, r = n-1;
        while(l<r){
            if(a[l] + a[r] < s){
                l++;
            }else if(a[l] + a[r] > s){
                r--;
            }else{
                pos = 1;
                break;
            }

        }

        if(pos){
            fr = i; sc=l; th=r;
            break;
        }
    }
    if(!pos){cout << "IMPOSSIBLE" << '\n'; return 0 ;}

    
    cout << m[a[fr]].back() << " ";
    m[a[fr]].pop_back();
    cout << m[a[sc]].back() << " ";
    m[a[sc]].pop_back();
    cout << m[a[th]].back();
    m[a[th]].pop_back();
}   

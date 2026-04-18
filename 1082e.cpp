#include <bits/stdc++.h>

using namespace std;

int const N = 500001;
vector<int> arr[N];
int main(){
    int n, c;

    cin >> n >> c;

    int a[n], p[n], s[n];
    for(int i =0;i<n;i++) cin >> a[i];
    int cnt = 0;
    for(int i =0;i<n;i++){
        arr[a[i]].push_back(i);
    }
    for(int i =0;i<n;i++){
        if(a[i] == c) cnt++;
        p[i] = cnt;
    }
    cnt=0;
    for(int i =n-1;i>=0;i--){
        if(a[i] == c) cnt++;
        s[i] = cnt;
    }

    int ans = 0;
    for(int i =0;i<n;i++){
        

    }
    

    
}

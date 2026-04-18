#include <bits/stdc++.h>

using namespace std;
int arr[2501][2501];
int main(){ 
    memset(arr, 0,sizeof(arr));
    int n;
    cin >> n;

    pair<int,int> a[n];
    for(int i =0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    map<int,int> m;
    sort(a, a+n);
    for(int i =0;i<n;i++) m[a[i].first] = i;
    
    sort(a, a+n, [&](pair<int,int> a, pair<int,int> b){ 
            return a.second < b.second;
        });

    for(int i = 0;i<n;i++) arr[m[a[i].first]][i]=1;
    
    for(int i=0;i<2501;i++){
        for(int j =1;j<2501;j++){
            cout << arr[i][j] << " " << arr[i][j-1] << '\n';
            if(i-1 >= 0) arr[i][j] += arr[i-1][j];
            arr[i][j] += arr[i][j-1];
        }
    }
    int ans =0;
    for(int i =0;i<2501;i++){
        int prev = 0;
        for(int j =0;j<2501;j++){
            if(prev != arr[i][j]) ans += arr[i][j];
            prev = arr[i][j];
        }
    }
    cout << ans << '\n';
}

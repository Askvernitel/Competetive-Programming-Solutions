#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int arr[3];
    for(int i =0;i<3;i++) cin >> arr[i];
    sort(arr, arr+3);
    
    if(arr[2] - arr[0] == 2){ 
        cout << 0 << '\n';
    }else if (arr[2]-arr[1] == 2 || arr[1] - arr[0] == 2){
        cout << 1 << '\n';
    }else{
        cout << 2 << '\n';
    }

    cout << max(arr[2]-arr[1]-1, arr[1]-arr[0]-1)<<'\n';


}

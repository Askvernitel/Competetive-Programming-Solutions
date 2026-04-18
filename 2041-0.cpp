#include <bits/stdc++.h>

using namespace std;
int arr[6];
int main(){
    
    for(int i =0;i<4;i++){
        int k;
        cin >> k;
        arr[k]=1;
    }
    int ans = 0;
    for(int i =1;i<6;i++){
        if(arr[i] == 0){
            ans = i;
            break;
        }
    }

    cout << ans;
}

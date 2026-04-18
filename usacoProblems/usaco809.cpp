#include <bits/stdc++.h>

using namespace std;
int n;
int arr[101];
int a[101];
bool check_valid(int idx, int endx){ 
    if(idx < 0) return false;
    if(a[idx] != -1 && a[idx] != 0) return false;
    arr[idx] = 1;
    for(int i = idx+1;i<=endx;i++){
        if(arr[i] == 1){
            return false;
        }else{ 
            arr[i] = -1;
        }
    }
    return true;
}
int main(){ 
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    if(a[0] !=0 && a[0] != -1){ 
        cout << -1 << '\n';
        return 0;
    }
    int max_ans =0, pos = 1, min_ans=0;
    arr[0] = 1;
    for(int i =1;i<n;i++){
        if(a[i] != -1){ 
            pos = check_valid(i-a[i], i);
            if(!pos) break;
        }
    }
    if(!pos){ 
        cout << -1 << '\n';
        return 0;
    }
    for(int i=0;i<n;i++){
        if(arr[i]==1) min_ans++;
        if(arr[i] != -1) max_ans++;
        
    }
    cout << min_ans << " " << max_ans << '\n';

}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int odd = 0, even =0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        (a[i] % 2)?odd++:even++;
    }
    bool is_even = true;
    int cnt =0;
    while(true){
        if(is_even){ 
            if(even>0) even--;
            else if(odd >= 2) odd-=2;
            else break;
        }else{
            if(odd > 0) odd--;
            else break;
        }
        cnt++;
        is_even=!is_even;
    }
    
    if(is_even && odd == 1){
        cnt--;
    }

    cout << cnt;


}

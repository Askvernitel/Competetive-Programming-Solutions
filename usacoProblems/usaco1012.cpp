#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin >> n;

    string s1, s2;

    cin >> s1 >> s2;
    int p = 0, cnt = 0;
    for(int i =0;i<n;i++){
        if(s1[i] != s2[i]){
            p = 1;
        }else if(p){
            cnt+=p;
            p=0;
        }
    }
    cnt+=p;

    cout << cnt;

}

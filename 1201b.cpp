#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int> s;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
        s.insert(a[i]);
    }



    for(int i =0;i<n;i++){
        if(s.find(a[i]*2) != s.end())
        s.erase(s.find(a[i]*2));
    }
    int pos = 1;
    for(int x: s){
        if(s.count(x) == 1){pos = 0; break;}
    }

    if(pos) cout << "YES";
    else cout << "NO";



}

#include <bits/stdc++.h>

using namespace std;

int main(){ 
    freopen("whereami.out", "w" , stdout);
    freopen( "whereami.in", "r", stdin);
    int n;
    cin >> n;


    string s;

    cin >> s;
    set<string> st;
    int ans = 0;
    for(int i =0;i<n;i++){
        int p = 1;
        for(int j =0;j<n-i;j++){
            string t="";
            for(int k = j; k <= j+i;k++){
                t.push_back(s[k]);
            }
            if(st.find(t) != st.end()){
                p = 0;
                break;
            }
            st.insert(t);
        }
        if(p){
            ans = i;
            break;
        }
    }

    cout << ans+1;

}

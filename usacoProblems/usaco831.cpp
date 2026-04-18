#include <bits/stdc++.h>

using namespace std;

set<string> one, two;
void check(set<int> s){ 
    if(s.size()==3) return;
    string str = "##";
    int idx = 0;
    for(int x:s){ 
        str[idx++]=x;
    }
    if(s.size() ==2){
        two.insert(str);
        return ;
    }
    one.insert(str);
    
}
int main(){
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    int t[3][3];

    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            char ch; cin >> ch;
            t[i][j] = (ch - 'A');
        }
    }

    set<int> s = {};
    s.insert(t[0][0]); s.insert(t[1][1]); s.insert(t[2][2]);
    check(s);
    s = {};
    s.insert(t[0][2]); s.insert(t[1][1]); s.insert(t[2][0]);
    check(s);
    for(int i=0;i<3;i++){
        s = {};
        for(int j =0;j<3;j++){
            s.insert(t[i][j]);
        }
        check(s);
        s={};
        for(int j =0;j<3;j++){
            s.insert(t[j][i]);
        }
        check(s);
    }
    cout << one.size() << '\n';
    cout << two.size() << '\n';
}

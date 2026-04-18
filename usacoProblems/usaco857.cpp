#include <bits/stdc++.h>

using namespace std;

vector<int> first, second;
int const N=10;
int turns = 4;
set<int> s;
int mf[21], ms[21];
void rec(int turn, int amount){
    if(turn == turns){
        s.insert(amount);
        return;
    }
    int n = first.size(), m = second.size();

    for(int i =0;i<((!(turn%2))?n:m);i++){
        if(!(turn%2)){
            if(mf[i]) continue;

            second.push_back(first[i]);
            mf[i] =1;
            rec(turn+1, amount-first[i]);
            mf[i] =0;
            second.pop_back();

       }else{
            if(ms[i]) continue;
            first.push_back(second[i]);
            ms[i] = 1;
            rec(turn+1, amount+second[i]);
            ms[i] = 0;
            first.pop_back();
       }
    }
}
int main(){
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    for(int i =0;i<N;i++){
        int num;cin >> num;
        first.push_back(num);
    }
    for(int i =0;i<N;i++){
        int num;cin >> num;
        second.push_back(num);
    }

 
    rec(0, 1000);

/*    for(int x:s){ 
        cout << x << " ";
    }*/
    cout << s.size() << '\n';


}

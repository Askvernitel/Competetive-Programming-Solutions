#include <bits/stdc++.h>

using namespace std;
set<int> difs;
int n;
priority_queue<int> sums; 
int arr[200004];
void calc(int x){
    if(x == 0 || x == n) return;
    auto it = difs.find(x);
    if(it != difs.end()){
        int a = *prev(it), b = *next(it);
        difs.erase(it);
        arr[b-x]--; arr[x-a]--; arr[b-a]++;
        sums.push(b-a);
    }else{
        difs.insert(x);
        auto it1 = difs.find(x);
        int a = *prev(it1), b = *next(it1);
        arr[b-a]--; arr[x-a]++; arr[b-x]++;
        sums.push(x-a);
        sums.push(b-x);
    }

}


int main(){
    string s;
    cin >> s;
    n = s.size(); int m;
    
    difs.insert(0); difs.insert(n);
    for(int i = 0;i<n;i++){
        if(s[i] != s[i+1]) difs.insert(i+1);
    }
    
    for(auto it = difs.begin(); next(it) != difs.end(); it++){
        sums.push(*next(it) - *it);
        arr[*next(it)-*it]++;
    }
    cin >> m;

    while(m--){
        int x;
        cin >> x;
        calc(x-1);
        calc(x);
        while(!arr[sums.top()]) sums.pop();
        
        cout << sums.top() << " ";

    }
}

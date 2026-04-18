#include <bits/stdc++.h>

using namespace std;


int main(){
//    freopen("lineup.in", "r", stdin);
  //  freopen("lineup.out", "w", stdout);
    int n;

    cin >> n;

    map<string, int> m1, m2;
    string arr[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    for(int i =0;i<8;i++) m1[arr[i]] = 0;

    map<string,vector<string>> m;
    for(int i =0;i<n;i++){
        string s1, s2;
        for(int j=0;j<6;j++){
            string str;
            cin >> str;
            if(j == 0) s1 =str;
            if(j == 5) s2 =str;
        }
        m[s1].push_back(s2);
        m[s2].push_back(s1);
        m2[s1]++;
        m2[s2]++;
    }
    set<vector<string>> s;
    
    for(auto &x:m){
        vector<string> pack;
        if(!m1[x.first] && x.second.size() == 2 ){
            m1[x.first] = 1;
            pack.push_back(x.first);
            for(string t:x.second){
                if(!m1[t]){
                    m1[t] = 1;
                    pack.push_back(t); 
                }
            }
            
        }
        sort(pack.begin(), pack.end()); s.insert(pack);
    }

    for(int i =0;i<8;i++){
        vector<string> v;
        if(!m1[arr[i]]){
            v.push_back(arr[i]);
        }
        s.insert(v);
    }

    for(auto t:s){
        for(string cow:t){
            cout << cow << '\n';
        }
    }
}

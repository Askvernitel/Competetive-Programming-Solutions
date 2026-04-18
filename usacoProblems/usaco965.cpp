#include <bits/stdc++.h>

using namespace std;
int const N = 8;
string arr[N] = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
map<string, set<string>> m;

int c[N];
vector<string> ans;
vector<string> prv = {};
void solve(){
    if(ans.size() == N){
        //prev=ans;
//        cout << "Hey!\n";
        for(int i =0;i<N;i++){
            set<string> z;
            for(string x:m[ans[i]]) z.insert(x);
            if(i-1 >= 0 && z.find(ans[i-1]) != z.end()) z.erase(z.find(ans[i-1]));
            if(i+1 <N && z.find(ans[i+1]) != z.end()) z.erase(z.find(ans[i+1]));
            if(z.size() != 0) return;
        }
        if(prv.size() != 0){
            for(int i =0;i<N;i++){
                if(ans[i] > prv[i]) return;
                if(ans[i] < prv[i]) break;
            }
            for(int i =0;i<N;i++){
                prv[i] = ans[i];
            }
        }else{
            for(int i =0;i<ans.size();i++) prv.push_back(ans[i]);
        }
        return;
    }

    for(int i =0;i<N;i++){
        if(c[i]) continue;
        c[i] = 1;
        ans.push_back(arr[i]);
        solve();
        c[i] = 0;
        ans.pop_back();
    }
}

int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout); 
    int n;
    cin >> n;
    
    for(int i =0;i<n;i++){
        string f, l;
        for(int j=0;j<6;j++){
            string s;
            cin >> s;
            if(j == 0) f=s;
            if(j == 5) l=s;
        }
        m[f].insert(l);
        m[l].insert(f);
    }
    solve();

    for(int i =0;i<prv.size();i++){
        cout << prv[i] << '\n';
    }
}

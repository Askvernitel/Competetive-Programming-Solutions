#include <bits/stdc++.h>
 
using namespace std;
void solve(){
    int n, c, p;
    cin >> n >> c >> p;
    vector<string> a[4];
    for(int i =0;i<n;i++){ 
        string str, type;
        cin >> str >> type;
        if(type == "noun"){ 
            a[0].push_back(str);
        }else if(type == "transitive-verb"){
            a[1].push_back(str);
        }else if(type == "intransitive-verb"){
            a[2].push_back(str);
        }else{ 
            a[3].push_back(str);
        }
    }
    int ans = 0;
    int nouns = a[0].size(), conjuctions = a[3].size(), intr = a[2].size();
    int t1=0, t2=0, per=0, com= 0, con = 0;
    for(int i =0;i<=(int)a[2].size();i++){
        int cur_nouns=nouns; int ps = p;
        int words = 0;
     
        int t1a = i;
        words+=t1a*2;
        cur_nouns-=t1a;
    
        if(cur_nouns < 0) continue; 
        
        int t2a = min({cur_nouns/2, (int)a[1].size(), 2*min(conjuctions,p)+max(0, p-conjuctions)});
        cur_nouns -= t2a*2;
        words+=t2a*3;
        int sents = t1a+t2a;
        int comb = (sents)/2;
        int conjs = min(conjuctions, comb);
        ps-=sents-conjs;
        if(ps < 0) continue;
        int comma_nouns =0;
        words+=conjs;
        if(t2a > 0){ 
            comma_nouns= min(cur_nouns, c);
            words+=comma_nouns;
        }

        if(words > ans){ 
            ans = words;
            t1=t1a;
            t2=t2a;
            con = conjs;
            com = comma_nouns;
        }
    }
    cout << ans << endl;
    if(!ans){ 
        cout << endl;
        return;
    }
    vector<vector<string>> sents;

    for(int i =0;i<t1;i++){
        sents.push_back({a[0].back(), a[2].back()});
        a[0].pop_back(); a[2].pop_back();
    }

    for(int i =0;i<t2;i++){
        sents.push_back({a[0].back(), a[1].back()});
        a[0].pop_back(); a[1].pop_back();
        sents.back().push_back(a[0].back());
        a[0].pop_back();
    }

    string outp = "";
    for(int i =0;i<(int)sents.size();i++){
        for(string s:sents[i]){ 
            outp += s+" " ;
        } 
        if(i%2==0 && con > 0){
            outp +=a[3].back() + " ";
            a[3].pop_back();
            con--;
        }else{ 
            outp.pop_back();
            outp+=". ";
        }
    }
    
    outp.pop_back();
    if(t2>0){ 
        outp.pop_back();
        for(int i =0;i<com;i++){
            outp += ", "+a[0].back();
            a[0].pop_back();
        }
        outp+=".";
    }
    cout << outp << endl;

}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

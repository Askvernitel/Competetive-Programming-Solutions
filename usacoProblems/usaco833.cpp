#include <bits/stdc++.h>


using namespace std;
map<string, string> parents;
map<string, vector<string>> children;
string cow1, cow2;

string skel(string name1, string s, string name2 ){ 
    name1+=" is the "; 
    name1+=s;
    name1+=" of ";
    name1+=name2;
    return name1;
}
void spb(string& s, string push, int cnt){ 
    for(int i = 0;i<cnt;i++){
        s+=push;
        s+="-";
    }
}

int dfs(string cow,  int depth){ 
    if(cow == cow2){ 
        return depth;
    }
    int res = -1;
    for(string child:children[cow]){ 
        res = max(res,dfs(child, depth+1));
    }
    return res;
}
int main(){
    freopen("family.in","r", stdin);
    freopen("family.out", "w", stdout);
    int n;
    cin >> n;

    cin >> cow1 >> cow2;
    for(int i = 0;i<n;i++){
        string m, c;

        cin >> m >> c;
        parents[c] = m;
        children[m].push_back(c);
    }
    string cow_copy=cow1;
    string ans = "NOT RELATED";
    int dist = 0; 
    while(cow1 != ""){
        int res = dfs(cow1,0);
        if(res != -1){ 
            string t = "";
            if(dist == 0){
                res-=2;
                spb(t,"great", res);
                if(res >= 0)
                    spb(t,"grand", 1);
                spb(t,"mother", 1);
                t.pop_back();
                ans = skel(cow_copy, t, cow2);
            }else if(res == 0){
                dist-=2;
                
                spb(t, "great", dist);
                if(dist>=0)
                    spb(t, "grand", 1);
                spb(t, "mother", 1);
                t.pop_back();
                ans = skel(cow2, t, cow_copy);
            }else if(res == 1 && dist == 1){
                ans = "SIBLINGS";
            }
            else if(res == 1){
                dist-=2;
                spb(t, "great", dist);
                spb(t, "aunt", 1);
                t.pop_back();
                ans = skel(cow2, t, cow_copy);
            }else if(dist == 1){ 
                res-=2;
                spb(t, "great", res);
                spb(t,"aunt", 1);
                t.pop_back();
                ans = skel(cow_copy, t ,cow2);
            }else{ 
                ans = "COUSINS";
            }

            break;
        }
        dist++;
        cow1 = parents[cow1];
    }

    cout << ans << '\n';
}

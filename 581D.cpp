#include <bits/stdc++.h>

using namespace std;
int const N = 6;

int cords[N];
char ct(int p){
    if(p <= 1) return 'A';
    else if(p <= 3) return 'B';
    else return 'C'; 

    return '?';
}
int nexti(int p){
    if(p%2) return p-1;
    else return p+1;
}
vector<int> findi(int p1, int p2){
    vector<int> ans;
    for(int i = 0;i<N;i++){
        if(p1 != i && p2 != i && cords[i] != -1){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){

    int maxv = 0, f = 0, s=0;
//    char ch = '';
    for(int i =0;i<N;i++){
        cin >> cords[i]; 
        if(cords[i] > maxv){maxv = cords[i]; f=i;}
    }
    s = nexti(f);
    char g[maxv][maxv];
    int height = maxv - cords[s];
    for(int i =0;i<cords[s];i++){
        for(int j=0;j<maxv;j++){
            g[i][j] = ct(f);
        }
    }
//    cout << cords[f] << " " << cords[s] << '\n';
    cords[f] = -1; cords[s] = -1;
    int t1[2], t2[2];
    int pos = 0, z=0;
    for(int i =0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(i!=j && j != nexti(i) && i != nexti(j) && cords[j] != -1 && cords[i] != -1){
//                cout << "Hi";
                int sum = cords[i] + cords[j];
                //cout<< cords[i] + cords[j] << '\n';
//                cout << height << '\n';
                vector<int> o = findi(i,j);
                //cout << (sum == maxv) << " " << ((cords[o[0]] == cords[o[1]]) && cords[o[0]] == height);
                if(sum == height && (cords[o[0]] == cords[o[1]]) && cords[o[0]] == maxv){
                    t1[0] = i; t2[0] = j;
                    if(i == nexti(o[0])){t1[1] = o[0]; t2[1] = o[1];}
                    else{t1[1] = o[1]; t2[1] = o[0];}
                    z=0;pos=1;
                }else if(sum == maxv && (cords[o[0]] == cords[o[1]]) && cords[o[0]] == height){
                    t1[0] = i; t2[0] = j;
//                    cout << "HEY"<<'\n';
                    if(i == nexti(o[0])){t1[1] = o[0]; t2[1] = o[1];}
                    else{t1[1] = o[1]; t2[1] = o[0];}
                    z=1;pos=1;
                }
            }
        }
        if(pos) break;
    }
    if(!pos){cout << -1; return 0;}
    int c = maxv - height;
    if(z){
        for(int i = c;i< c+ height;i++){
            for(int j=0;j<cords[t1[0]];j++){
                g[i][j] = ct(t1[0]);
            }
        }
        for(int i =c;i< c+ height;i++){
            for(int j=cords[t1[0]];j<maxv;j++){
                g[i][j] = ct(t2[0]);
            }
        }
    }else{
        for(int i = c;i< c+cords[t1[0]];i++){
            for(int j =0;j<maxv;j++){
                g[i][j] = ct(t1[0]);
            }
        }
        c = c+cords[t1[0]];
        for(int i = c;i< c+cords[t2[0]];i++){
            for(int j =0;j<maxv;j++){
                g[i][j] = ct(t2[0]);
            }
        }
    }
    cout << maxv << '\n';    
    for(int i =0;i<maxv;i++){
        for(int j =0;j<maxv;j++){
            cout << g[i][j];
        }
        cout << '\n';
    }
}

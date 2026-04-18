#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int pref[n+1];
    map<int,int> spref, spref1;
    pref[0]=0;
    for(int i=1;i<=n;i++){
        int v=(a[i-1] <= k)? 1:-1;
        pref[i]=pref[i-1]+v;
        spref[pref[i]]++;
    }
    spref1=spref;
    int suf[n+1];
    map<int,int> ssuf, ssuf1;
    suf[n]=0;
    for(int i=n-1;i>=0;i--){
        int v=(a[i] <= k)? 1:-1;
        suf[i]=suf[i+1]+v;
        ssuf[suf[i]]++;
    }
    ssuf1=ssuf;
    bool found = 0;

    for(int i=1;i<n-1;i++){
        spref[pref[i]]--;
        ssuf[suf[i]]--;
        int resp = 0, ress=0;
        if(spref[pref[i]] == 0){
            spref.erase(pref[i]);
        }
        if(ssuf[suf[i]] == 0){ 
            ssuf.erase(suf[i]);
        }
        int t = pref[i];
        
        if(t >= 0){ 
            resp++;
            ress++;
        }
        auto it1 = spref.lower_bound(max(t,0));
        auto it2 = ssuf.lower_bound(0);
        if(it1 == spref.end() && it2 == ssuf.end()){
            continue;
        }
        if(it1 != spref.end()){ 
            resp++;
        }

        if(it2 != ssuf.end()){ 
            ress++;
        }
        if(ress >= 2 || resp >= 2){
            found = 1;
            break;
        }

    }

    for(int i =0;i<n-2;i++){

        spref1[pref[n-i]]--;
        ssuf1[suf[i]]--;
        if(spref1[pref[n-i]] == 0){
            spref1.erase(pref[n-i]);
        }
        if(ssuf1[suf[i]] == 0){ 
            ssuf1.erase(suf[i]);
        }
        int resp = 0, ress=0;
        int t = suf[i];

        if(t >= 0){ 
            ress++;
            resp++;
        }
        auto it1 = ssuf1.lower_bound(max(t,0));
        auto it2 = spref1.lower_bound(0);
        if(it1 == ssuf1.end() && it2 == spref1.end()){
            continue;
        }
        if(it1 != ssuf1.end()){ 
            resp++;
        }

        if(it2 != spref1.end()){ 
            ress++;
        }
        if(ress >= 2 || resp >= 2){ 
            found = 1;
            break;
        }
    }
    cout << ((found)?"YES":"NO") << '\n';
    

}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

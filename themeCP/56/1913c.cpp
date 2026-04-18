#include <bits/stdc++.h>

using namespace std;
void solve(){
	int m;
	cin >> m;
	map<int,int> mt;
	while(m--){
		int t, v;

		cin >> t >> v;

		if(t == 1) {
			mt[v]++;
		}else{
			int p = v;
			int cnt = 0;
			map<int,int> used;
			bool pos = 1;
			while(p != 0) {
				if(p & 1){
					if(mt[cnt] == 0){
						int w = (1<<cnt);
						int c =cnt;
						bool found = 0;
						while(c > 0){ 
							c--;
							int tt=(1<<c)*mt[c];
							if(w-tt <= 0){
								w-=tt;
								int l=-1, r=mt[c]+1;
								while(r-l>1){
									int m = (r+l)/2;
									if(w+(m*(1<<c)) >= 0) r = m;
									else l = m;
								}
								w += r*(1<<c);
								used[c]+=(mt[c]-r);
								mt[c]=r;
								found=1;
								break;
							}else{
								w-=tt;
								used[c]+=mt[c];
								mt[c]=0;
							}
						}
						if(!found){ 
							pos =0;
							break;
						}
					}else{
						mt[cnt]--;
						used[cnt]++;
					}
				}
				cnt++;
				p=(p >> 1);
			}
			for(auto &[c,d]:used){
				mt[c]+=d;
			}
			if(pos){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}
}
int main(){
	solve();
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	map<int,int> m,u;
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	
	map<int,int> b[n];
	for(int i =0;i<n;i++){
		int v=a[i];
		int cur = 2;
		while(v>1){
			if(v%cur){
				if(cur==2)cur++;
				else cur+=2;
			}else{
				m[cur]++;
				b[i][cur]++;
				v/=cur;
			}
		}
	}
	int ans = 1;
	for(auto &[c,d]:m){u[c] = d/n;  if(u[c]!=0)ans *= pow(c,u[c]);}
	int ops=0;	
	for(int i = 0;i<n;i++){
		for(auto &[c,d]:u){
			if(d != 0){
				ops+=max((int)0,(d-b[i][c]));
			}
		}
	}
	cout << ans << " " << ops;
}

#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
void solve(){
	int n, m, x;
	cin >> n>> m >> x;
	pair<int, char> a[m];
	for(int i =0;i<m;i++) cin >> a[i].F >> a[i].S;
	
	int cur[n], nxt[n];	
	memset(cur, 0, sizeof(cur));
	memset(nxt, 0, sizeof(nxt));
	cur[x-1] = 1;
	for(int i =0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(!cur[j]) continue;
			int v=a[i].F;
			if(a[i].S == '?'){ 
				nxt[(j+v)%n] = 1;
				nxt[(n+j-v)%n] = 1;
				
			}else if(a[i].S =='1'){
				nxt[(n+j-v)%n] = 1;
			}else{
				nxt[(j+v)%n] = 1;
			}
		}

		memcpy(cur, nxt, sizeof(nxt));
		memset(nxt, 0, sizeof(nxt));
	}
	int sz = 0;

	for(int i =0;i<n;i++)
		if(cur[i]) sz++;
	cout << sz << '\n';
	for(int i =0;i<n;i++){
		if(cur[i]){
			cout << i+1 << " ";
		}
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}

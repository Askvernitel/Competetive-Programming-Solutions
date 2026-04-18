#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,m, k;
	cin >> n >> m >> k;
	int a[n], b[m];	
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	
	for(int i =0;i<m;i++){
		cin >> b[i];
	}
	sort(a, a+n);
	sort(b, b+m);
	int t[k+1];
	memset(t, 0, sizeof(t));
	int i = 0;
	while(i<n && a[i] <= k){
		t[a[i]]=-1;
		i++;
	}
	i=0;
	while(i <m && b[i] <= k){
		if(t[b[i]] == -1 || t[b[i]] == 1){ 
			t[b[i]] = 1;
		}else{
			t[b[i]]=-2;
		}
		i++;
	}
	int u = k/2, p = k/2;
	int pos =1;
	for(int i =1;i<=k;i++){
		if(t[i] == -1){
			u--;
		}else if(t[i] == -2){
			p--;
		}else if(t[i] == 0){
			pos=0;
			break;
		}
	}
	if(u < 0 || p < 0 || !pos){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}

#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, x;
	cin >> n >> x;
	int p[n+1];
	for(int i =1;i<=n;i++) p[i]=i;
	p[1] = x;
	p[n] = 1;

	if(n%x){ 
		cout << -1 << '\n';
		return;
	}
	int cur = x;
	if(cur < n) p[cur] = n;
	int u=n;

	for(int i = x+x;i<n;i+=x){
		if(!(n%i) && !(i%cur)){ 
			swap(p[cur], p[i]);
			cur = i;
		}
	}
	for(int i =1;i<=n;i++){
		cout << p[i] << " ";
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}

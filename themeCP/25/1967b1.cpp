#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b){
	if(a==0) return b;
	return gcd(b, a%b);
}
void solve(){
	int n,m;
	cin >> n >> m;
	
	for(int i =0;i<=n+m;i++){
		gcd(i,
	}


}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}

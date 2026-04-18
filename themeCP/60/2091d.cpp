#include <bits/stdc++.h>

using namespace std;
int n, m, k, p;
bool f(int x){ 
	return (p <= ((x)*(m/(x+1)) + (m%(x+1))));
}
void solve(){
	cin >> n >> m >> k;
	p = (k%n)?(k/n + 1):(k/n);
	
	int l = 0, r = m+2;
	while(r-l>1){ 
		int md = (l+r)/2;
		if(f(md)){ 
			r = md;
		}else{
			l = md;
		}
	}
	cout << r << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
